#!/bin/bash
files=0
directories=0

echo "Files:"
for entry in *
do
    if [ -f "$entry" ]; then
        echo "$entry"
        ((files++))
    fi
done

echo "Directories:"
for entry in *
do
    if [ -d "$entry" ]; then
        echo "$entry"
        ((directories++))
    fi
done

echo "Number of files: $files"
echo "Number of directories: $directories"