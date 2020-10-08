#2.)Write a Shell program to accept two parameters perform File Test and display their attributes
#with suitable message if not display a suitable  message to pass right number of arguments
#!bin/bash

if test $# -eq 2
then
	echo "Two Positional Parameters Supplied: $1 and $2"
	echo "Number of characters: `wc -c $1`, `wc -c $2`"
	echo "Number of words: `wc -w $1`, `wc -w $2`"
	echo "Number of lines: `wc -l $1`, `wc -l $2`"
elif test $# -lt 2
then
	echo "Only $# Command Line Argument received instead of 2."
else
	echo "To Many parameters supplied, Received $# parameters instead of 2."
fi
