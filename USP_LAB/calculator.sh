#!/bin/sh

echo "Enter the expression"
read exp
result=`echo $exp|bc`
echo "result: $result"