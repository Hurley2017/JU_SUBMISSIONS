#!/bin/bash
for file in *~
do
    if [ -f "$file" ]; then
        rm "$file"
    fi
done
echo "Successfully removed all temporary files!"
