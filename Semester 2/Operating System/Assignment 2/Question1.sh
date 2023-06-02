echo "Start : "
dir_content=$(ls)
IFS=$'\n'
read -rd '' -a files <<< "$dir_content"
# echo $dir_content
for file in $files
do 
    echo "$file"
    # if [ -f $file ]
    # then
    #     echo "$file is a file"
    # elif [ -d $file ]
    # then
    #     echo "$file is a directory"
    # else
    #     echo "$file is not valid"
    # fi
done