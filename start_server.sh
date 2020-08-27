sh ~/Downloads/flink/flink-2.11.0/src/start-cluster.sh
sh ~/Downloads/kafka/bin/zookeeper-server-start.sh ~/Downloads/kafka/config/zookeeper.properties &
sh ~/Downloads/kafka/bin/kafka-server-start.sh ~/Downloads/kafka/config/server.properties &