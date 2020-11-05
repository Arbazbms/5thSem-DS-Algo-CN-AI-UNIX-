#! bin/shell

echo "Enter value of a:"
read num
echo "Enter value of b:"
read power

temp=$power
ans=1
while [ $temp -ne 0 ]
do
        ans=`expr $ans \* $num`
        temp=`expr $temp - 1`
done

echo "$num ^ $power = $ans"


