#! bin/bash
echo "Start : "
dirs=$(ls)
count_file=0
count_dir=0
IFS=$'\n'
read -rd '' -a dir <<< "$dirs"
echo "All The Files : "
for entry in "${dir[@]}"
do
    if [ -f "$entry" ]
    then
        count_file=$(($count_file+1))
        echo "$count_file) $entry"
    fi
done
echo "All The Directories : "
for entry in "${dir[@]}"
do
    if [ -d "$entry" ]
    then
        count_dir=$(($count_dir+1))
        echo "$count_dir) $entry"
    fi
done
echo "Total Files : $count_file"
echo "Total Directories : $count_dir"