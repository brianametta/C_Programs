#!/bin/bash

echo "Assignment #2-1, Briana Wright, masc1429"

FNAME=`grep "100" $1 | cut -d "," -f1`
LNAME=`grep "100" $1 | cut -d "," -f2`

echo $FNAME $LNAME

grep "$FNAME $LNAME" $2 | cut -d \, -f2
grep "$FNAME $LNAME" $2 | cut -d \, -f3