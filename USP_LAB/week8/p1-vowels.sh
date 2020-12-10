echo "Enter Filename : \c"
read fname
s=`tr -cd "[aeiouAEIOU]"<$fname | wc -c`
echo $s