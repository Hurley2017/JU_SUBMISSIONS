echo "Start : "
data=$(<index.txt)
IFS=$'\n'
read -rd '' -a lines <<< "$data"
for line in "${lines[@]}"
do
    sum=0
    IFS=' '
    read -rd '' -a num <<< "$line"
    for digit in "${num[@]}"
    do
        sum=$(($sum+$digit))
    done
    echo $sum
done 