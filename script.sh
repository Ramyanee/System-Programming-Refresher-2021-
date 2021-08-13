#! /usr/bin/bash

if [ ! -e "$1" ] 
then         
   echo "no such directory"         
   exit 4 
else 
cd $1
fi


for file in *.c
do
    gcc -g3 -o3 $file -o ${file%.c}.out
done

status=$?
if [ $status -ne 0 ]
then
    echo "Could not compile some files or .c files do not exist in the given"
    exit 0
fi