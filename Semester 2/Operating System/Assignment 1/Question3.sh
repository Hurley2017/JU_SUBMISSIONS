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
sum=0
temp=0
while [ $number -gt 9 ]
do
    temp=$(($number%10))
    sum=$(($sum + $temp))
    number=$(($number/10))
done
sum=$(($sum + $number))
echo "Summation of 5 digits are $sum."