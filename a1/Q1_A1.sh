#! /usr/bin/bash

#read the number upto which 
#whose factorial is to be calculated
# -p to prompt the user to enter N
read -p 'enter the number to compute factorial of:  ' n

if [ $n -lt 0 ]; then
echo "factorial of negative numbers not defined"
exit
elif [ $n -eq 0 ]; then
echo 1
exit
fi

fact=1
#running the loop 
#to compute factorial
for((i=1;i<$n+1;i++)); do

fact=$(bc <<< "$fact*$i");

done
echo $fact