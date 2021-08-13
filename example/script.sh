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