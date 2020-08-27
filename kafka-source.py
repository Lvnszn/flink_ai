import os
import time
from subprocess import Popen
from typing import Dict

import pandas as pd
import yaml
from ai_flow import Watcher
from ai_flow.rest_endpoint.service.client.aiflow_client import AIFlowClient
from kafka import KafkaProducer, KafkaAdminClient
from kafka.admin import NewTopic


class Source(object):
    """
    Generate inference online read example messages when listening to the source notification.
    """

    def __init__(self):
        super().__init__()
        self._yaml_config = None
        with open(os.path.dirname(os.path.abspath(__file__)) + '/source.yaml', 'r') as yaml_file:
            self._yaml_config = yaml.load(yaml_file)
        self._aiflow_client = AIFlowClient(server_uri=self._yaml_config.get('master_uri'))

    def listen_notification(self):

        class SourceWatcher(Watcher):

            def __init__(self, yaml_config: Dict):
                super().__init__()
                self._yaml_config = yaml_config

            def process(self, listener_name, notifications):
                self.process_notification()

            def process_notification(self):
                bootstrap_servers = self._yaml_config.get('bootstrap_servers')
                read_example_topic = self._yaml_config.get('read_example_topic')
                write_example_topic = self._yaml_config.get('write_example_topic')
                admin_client = KafkaAdminClient(bootstrap_servers=bootstrap_servers)
                topics = admin_client.list_topics()
                if read_example_topic in topics:
                    process = Popen(
                        args=['kafka-topics.sh', '--bootstrap-server', bootstrap_servers, '--delete', '--topic',
                              read_example_topic, ], shell=False)
                    print('Delete kafka topic {} status: {}'.format(read_example_topic, process.wait()))
                if write_example_topic in topics:
                    process = Popen(
                        args=['kafka-topics.sh', '--bootstrap-server', bootstrap_servers, '--delete', '--topic',
                              write_example_topic, ], shell=False)
                    print('Delete kafka topic {} status: {}'.format(write_example_topic, process.wait()))
                # Create inference online read example topic.
                admin_client.create_topics(
                    new_topics=[NewTopic(name=read_example_topic, num_partitions=1, replication_factor=1)])
                # Create inference vector write example topic.
                admin_client.create_topics(
                    new_topics=[NewTopic(name=write_example_topic, num_partitions=1, replication_factor=1)])
                self.generate_read_example()

            def generate_read_example(self):
                """
                Generate inference online read example messages.
                """
                bootstrap_servers = self._yaml_config.get('bootstrap_servers')
                read_example_topic = self._yaml_config.get('read_example_topic')
                # Read inference online read example.
                df = pd.read_csv(filepath_or_buffer=self._yaml_config.get('dataset_uri'), delimiter=';', header=None)
                producer = KafkaProducer(bootstrap_servers=[bootstrap_servers])
                for index, row in df.iterrows():
                    print('Send inference online read example message: topic=%s, key=%s, value=%s' % (
                        read_example_topic, row.get(1), '%s,%s,%s' % (row.get(1), row.get(2), row.get(3))))
                    # Send inference online read example messages.
                    producer.send(read_example_topic,
                                  key=bytes(row.get(1), encoding='utf8'),
                                  value=bytes('%s,%s,%s' % (row.get(1), row.get(2), row.get(3)), encoding='utf8'))
                    time.sleep(self._yaml_config.get('time_interval') / 1000)

        self._aiflow_client.start_listen_notification(listener_name='source_listener',
                                                      key=self._yaml_config.get('notification_key'),
                                                      watcher=SourceWatcher(self._yaml_config))


source = Source()
source.listen_notification()
