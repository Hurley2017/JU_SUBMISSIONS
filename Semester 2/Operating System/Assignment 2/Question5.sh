#! bin/bash
dir_content=$(ls)
current_dir=${pwd}
for file in $dir_content
do
    Query=$(du -b $file)
    IFS=$'\t'
    read -ra '' -a file_size <<< "$Query"
    echo "File Name : $file || File Size : ${file_size[0]}"
done
echo $(du -b $current_dir)
Current_Dir_Size=$(du -a)
echo "Current Directory Size in KB : "
echo $Current_Dir_Size