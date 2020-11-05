#!/bin/sh
#Shell Sample Script

echo "Give two numbers:"
read a
read b
echo "Add : $(($a+$b))"
echo "Subtract : $(($a-$b))"
echo "Multiply : $(($a*$b))"
echo "Divide : $(($a/$b))"
echo "Mod : $(($a%$b))"