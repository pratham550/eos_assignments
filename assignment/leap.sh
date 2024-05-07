echo "Enter year :"
read year
rem=$(($year % 4))
if [ $rem -eq 0 ]
then
	echo "$year is a leap year"

else
	echo "$year is not leap year"
fi
