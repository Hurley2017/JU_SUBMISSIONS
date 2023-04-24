#!/bin/bash
while read a b c
do
    echo $((a + b + c))
done < input.txt