#!/bin/bash

echo "Assignment #5-3, Briana Wright, masc1429"

gcc prog5-1.c -llua -lm -L /home/ma/j/lindenea/lua/lib/ -I /home/ma/j/lindenea/lua/headers/ -R /home/ma/j/lindenea/lua/lib

./a.out $1 > temp.output                #Execute applicant's file passed in

if diff -q $2 temp.output               #check if correct.output = temp.output
        then echo "Passed Test"         #Print Passed Test if output is equal

else
        echo "Failed Test"              #Print Failed Test if output is inequal
fi