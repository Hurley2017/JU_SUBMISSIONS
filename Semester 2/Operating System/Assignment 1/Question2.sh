#!bin/bash
echo "Enter Basic Salary : "
read basic
increament=$(($basic*25/100))
echo "Increament added : $increament"
net=$(($increament+$basic))
echo "Net Salary is : $net"