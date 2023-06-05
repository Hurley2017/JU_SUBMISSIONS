echo "Start : "
vendor_id=$(head /proc/cpuinfo | grep "vendor_id")
model_name=$(head /proc/cpuinfo | grep "model name")
cpu_MHz=$(head /proc/cpuinfo | grep "cpu MHz")
cache_size=$(head /proc/cpuinfo | grep "cache size")
IFS=':' 
read -ra '' -a vendor <<< "$vendor_id"
IFS=':' 
read -ra '' -a Model <<< "$model_name"
IFS=':' 
read -ra '' -a CPU <<< "$cpu_MHz"
IFS=':' 
read -ra '' -a Cache <<< "$cache_size"
echo "Vendor ID : ${vendor[1]}"
echo "Model Name : ${Model[1]}"
echo "CPU MHz : ${CPU[1]} MHz"
echo "Cache Size : ${Cache[1]} X 8"