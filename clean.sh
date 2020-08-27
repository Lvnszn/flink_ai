ps aux | grep zoo | awk -F ' ' '{print $2}' | xargs kill -9
ps aux | grep kafka-source | awk -F ' ' '{print $2}' | xargs kill -9
ps aux | grep tianchi_main | awk -F ' ' '{print $2}' | xargs kill -9
ps aux | grep ai_flow_master | awk -F ' ' '{print $2}' | xargs kill -9
sh ~/Downloads/flink/flink-2.11.0/src/stop-cluster.sh
sh ~/Downloads/kafka/bin/zookeeper-server-stop.sh ~/Downloads/kafka/config/zookeeper.properties
sh ~/Downloads/kafka/bin/kafka-server-stop.sh ~/Downloads/kafka/config/server.properties
