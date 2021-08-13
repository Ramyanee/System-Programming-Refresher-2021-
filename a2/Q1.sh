#! /bin/bash

#extracting time by using %T descriptor from the date command
#using if-elif-else to compare the system time and give the appropriate output.

t="$(date +%T)"


if { [ "$t" > "03:00:00" ] || [[ "$t" == "03:00:00" ]]; } && [[ "$t" < "12:00:00" ]]; then
echo "Good Morning!!!"
elif { [ "$t" > "12:00:00" ] || [[ "$t" == "12:00:00" ]]; } && [[ "$t" < "17:00:00" ]]; then
echo "Good Afternoon!!!"
elif { [ "$t" > "17:00:00" ] || [[ "$t" == "17:00:00" ]]; } && [[ "$t" < "23:59:00" ]]; then
echo "Good Evening!!!"
else
echo "Good Night :)"
fi
	
