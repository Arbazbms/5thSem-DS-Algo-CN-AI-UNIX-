#3.)Write a shell program to find biggest of three Numbers using  read statement or positional parameter technique.

#!bin/bash

echo "Enter Num1"
read num1
echo "Enter Num2"
read num2
echo "Enter Num3"
read num3

if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then
    echo "Largest is $num1"
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]
then
    echo "Largest is $num2"
else
    echo "Largest is $num3"
fi
