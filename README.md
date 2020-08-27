## 官方说明
1.下载https://tianchi.aliyun.com/competition/entrance/531800/information 数据集train_data.csv和label_file.csv文件到data_set目录; \
2.设置PYTHONPATH：export PYTHONPATH=[python_codes目录路径] \
3.配置环境变量：\
必填：\
ENV_HOME=[tianchi_ai_flow目录路径]\
TASK_ID=[任意整数]\
SERVING_HTTP_PATH=[Cluster Serving HTTP Jar包路径]\
可选：\
REST_HOST=[Flink Rest Host，默认为localhost]\
REST_PORT=[Flink Rest Port，默认为8081]\
CLUSTER_SERVING_PATH=[Cluster Serving运行目录，默认为/tmp/cluster-serving]\
4.启动AIFlow Master：python [ai_flow_master.py绝对路径]；\
5.修改source.yaml的dataset_uri配置项值为data_set目录的路径，启动Kafka Source：python [kafka-source.py绝对路径]；\
6.运行Tianchi Workflow：python [tianchi_main.py绝对路径]；\
7.查看AIFlow Master终端输出日志。

## 如何安装依赖

```buildoutcfg
pip3 install package/whl_dependencies/analytics_zoo_serving-0.9.0.dev0-py3-none-any.whl
pip3 install proxima-tianchi-master-668a0a87cb2a4aa1c68443b1ab05ee5a80008cb4/python/pyproxima2-2.2.0_lite-cp37-cp37m-linux_x86_64.whl
pip3 install package/whl_dependencies/ai_flow-0.1-py3-none-any.whl
pip3 install apache-flink==1.11.0
pip3 install kakfa-python==2.0.0
```

## 如何运行
安装好了环境之后，根据自己的地址设置init_env然后运行下面的命令
```shell script
source init_env
make run
```

## 如何删除正在跑的进程
```shell script
sh clean.sh
```


## Q&A

如果出现问题，
```buildoutcfg
conda remove [package]
```
