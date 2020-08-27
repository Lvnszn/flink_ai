ps aux | grep zoo | awk -F ' ' '{print $2}' | xargs kill -9
ps aux | grep kafka-source | awk -F ' ' '{print $2}' | xargs kill -9
ps aux | grep tianchi_main | awk -F ' ' '{print $2}' | xargs kill -9
ps aux | grep ai_flow_master | awk -F ' ' '{print $2}' | xargs kill -9