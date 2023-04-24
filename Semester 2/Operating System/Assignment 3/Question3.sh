#!/bin/bash
total=0
for entry in *
do
    if [ -f "$entry" ]; then
        size=$(stat -c%s "$entry")
        ((total += size))
    fi
done
echo "Total bytes used: $total"