export GLOG_logtostderr=1
export GLOG_v=2
export model_dir=/root/20210602_unified_transformer_server

cp ~/*.pem . -rf
./websocket_server_main --port 10087 --chunk_size 16  --model_path $model_dir/final.zip --dict_path $model_dir/words.txt 