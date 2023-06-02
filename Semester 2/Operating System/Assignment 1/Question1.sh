#!/bin/bash
echo "Enter Length : "
read length
echo "Enter Breadth : "
read breadth
area=$(($length*$breadth))
echo "Area of Rectangle : $area"
