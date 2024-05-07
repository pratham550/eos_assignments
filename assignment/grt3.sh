#!/bin/bash

echo -n "Enter the three numbers"
read num1 num2 num3

max=0

if [ $num1 -gt $num2 -a $num1 -gt $num3 ]
then
	echo "num1 is greater than num2 and num3"
	max=$num1
elif [ $num2 -gt $num1 -a $num2 -gt $num3 ]
then
	echo "num2 is greater than num1 and num3"
	max=$num2
elif [ $num3 -gt $num1 -a $num3 -gt $num2 ]
then
	echo "num3 is greater than num1 and num2"
	max=$num3
else
	echo "All are equal"
	max=$num1 $num2 $num3
fi

echo "maximum value = $max"
