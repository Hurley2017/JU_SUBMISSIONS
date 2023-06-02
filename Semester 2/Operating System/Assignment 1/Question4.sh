#! bin/bash
#! bin/bash
echo "Enter 5 digit number : "
read number
if [ $number -gt 10000 ] 
    then
        if [ $number -lt 100000 ]
            then
                echo "5 digit."
            else
                echo "no"
                exit
        fi
    else
        echo "no"
        exit
fi
temp=0
reverse=0
while [ $number -gt 9 ]
do
    temp=$(($number%10))
    reverse=$(($reverse + $temp))
    reverse=$(($reverse*10))
    number=$(($number/10))
done
reverse=$(($reverse + $number))
echo "Reverse of 5 digits are $reverse."