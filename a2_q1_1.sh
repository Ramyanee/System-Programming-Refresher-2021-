#! /bin/bash

t=$(date +%H)
echo $t

if [  $t -gt 3 -a  $t -lt 12 ]; then
echo "Good Morning!!!"
elif [  $t -gt 12 -a  $t -lt  17 ]; then
echo "Good Afternoon!!!"
elif [  $t -gt 17 -a  $t -lt 1  ]; then
echo "Good Evening!!!"
else
echo "Good Night"
fi
	
