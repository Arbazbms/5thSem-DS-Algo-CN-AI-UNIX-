# 1.	Shell script to  find the FACTORIAL OF A NUMBER using 
         Looping construct

#!bin/bash

echo "Enter a Number : "
read n

fact=1

while [ $n -gt 1 ]
do
fact=$((fact * n))
n=$((n - 1))
done

echo "Factorial: $fact"
