# 1.)Write an Interactive Shell program to check whether a  number is zero,positive or Negative

echo "Enter a Number"
read num

if [ $num -lt 0 ]
then
    echo "Negative"
elif [ $num -gt 0 ]
then
    echo "Positive"
else
    echo "Neither Positive Nor Negative (Zero)."
fi
