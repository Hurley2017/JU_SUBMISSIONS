#! bin/bash
echo "Start : "
cd TestDir
target_files=$(ls *.exe)
IFS=$'\n'
read -rd '' -a scripts <<< "${target_files}"
for script in "${scripts[@]}"
do
    echo "Renaming $script to ${script%.exe}.sh"
    mv "$script" "${script%.exe}.sh"
done