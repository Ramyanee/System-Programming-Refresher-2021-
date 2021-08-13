#! /bin/bash

t="$(date +%T)"


if [[ "$t" > "03:00:00" &&  "$t" < "12:00:00" ]]; then
echo "Good Morning!!!"
elif [[ "$t" > "12:00:00" && "$t" < "17:00:00" ]]; then
echo "Good Afternoon!!!"
elif [[ "$t" > "17:00:00" &&  "$t" < "24:00:00" ]]; then
echo "Good Evening!!!"
else
echo "Good Night"
fi
	
