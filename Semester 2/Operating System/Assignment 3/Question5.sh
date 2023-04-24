#!/bin/bash
for file in *.sh
do
    if [ -f "$file" ]; then
        mv "$file" "${file%.sh}.exe"
    fi
done
echo "Successfully renames all .sh files to .exe"