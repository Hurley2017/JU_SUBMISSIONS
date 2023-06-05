#! bin/bash
echo "Start : "
scripts=$(ls *.sh)
count=0
IFS=$'\n'
read -rd '' -a script <<< "${scripts}"
for s in "${script[@]}"
do 
    count=$(($count+1))
done
echo "Total scripts are $count."