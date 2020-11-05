echo "Enter the temperature in Fahrenheit"
read f
d=`expr $f - 32`
c=`expr $d \* 5 / 9`
echo "Temperature in Celsius: $c"

