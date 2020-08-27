base=python
jar=java -jar

run:
	$(jar) /home/jason/Documents/workspace/tianchi_ai_flow/package/jar_dependencies/analytics-zoo-bigdl_0.10.0-spark_2.4.3-0.9.0-20200825.195144-78-http.jar &
	$(base) /home/jason/Documents/workspace/tianchi_ai_flow/ai_flow_master.py &
	$(base) /home/jason/Documents/workspace/tianchi_ai_flow/kafka-source.py &
	$(base) /home/jason/Documents/workspace/tianchi_ai_flow/package/python_codes/tianchi_main.py &

clean:

