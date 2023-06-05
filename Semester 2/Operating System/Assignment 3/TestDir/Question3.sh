#! bin/bash
echo "Start : "
size_info=$(du -b)
IFS=$'\n'
read -rd '' -a lines <<< "$size_info"
IFS=$'\t'
read -rd '' -a size <<< "${lines[1]}"
echo "Total number of bytes used is : ${size[0]} bytes"