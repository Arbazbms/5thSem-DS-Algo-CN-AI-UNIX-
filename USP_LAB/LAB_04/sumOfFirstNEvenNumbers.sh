#2.	Shell script to  find the SUM OF EVEN NUMBERS UPTO N using 
          Looping construct.
          
          
#!bin/bash
echo "Enter the value of n: "
read n
temp=$n
sum=0
while [ $temp -gt 1 ]
do
    if [ `expr $temp % 2` -eq 0 ]
    then
        sum=`expr $sum + $temp`
    fi
    temp=`expr $temp - 1`
done

echo "Sum of first $n even numbers: $sum"
