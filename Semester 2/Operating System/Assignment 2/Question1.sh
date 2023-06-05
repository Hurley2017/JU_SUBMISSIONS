echo "Start : "
dir_content=$(ls)
#split the string into array by delimiter newline
IFS=$'\n'
read -rd '' -a files <<< "$dir_content"
for file in "${files[@]}"
do 
    if [ -f $file ]
    then
        echo "$file is a file"
    elif [ -d $file ]
    then
        echo "$file is a directory"
    else
        echo "$file is not valid"
    fi
done