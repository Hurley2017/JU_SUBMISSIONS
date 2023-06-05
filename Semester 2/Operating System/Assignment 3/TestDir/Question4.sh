#! bin/bash
echo "Start : "
temps=$(ls *~)
echo $temps
IFS=$'\n'
read -rd '' -a temp <<< "$temps"
# echo ${temp[@]}
for t in "${temp[@]}"
do
    echo "Removing $t"
    rm "$t"
done