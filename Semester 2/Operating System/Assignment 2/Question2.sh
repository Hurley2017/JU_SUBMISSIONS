#! bin/bash
echo "Start : "
current_path=$(pwd)
path_vars=$PATH
IFS=":"
read -rd "" -a dirs <<< "$path_vars"
for path in "${dirs[@]}"
do
    echo "Directory : $path"
    permissions=$(ls -l $path)
    IFS=" "
    read -rd '' -a perm <<< "$permissions"
    echo "Permissions : ${perm[0]} ${perm[5]} ${perm[6]} ${perm[7]}."
done