#!/bin/bash

echo "Assignment #2-3, Briana Wright, masc1429"

if grep -q "Assignment #1" $1
then
        echo "$1 Assignment #1"
elif grep -q "Assignment #2" $1
then
        echo "$1 Assignment #2"
elif grep -q "Assignment #3" $1
then
        echo "$1 Assignment #3"
else
        echo "$1 Assignment #4"
fi

if grep -q "Assignment #1" $2
then
        echo "$2 Assignment #1"
elif grep -q "Assignment #2" $2
then
        echo "$2 Assignment #2"
elif grep -q "Assignment #3" $2
then
        echo "$2 Assignment #3"
else
        echo "$2 Assignment #4"
fi

if grep -q "Assignment #1" $3
then
        echo "$3 Assignment #1"
elif grep -q "Assignment #2" $3
then
        echo "$3 Assignment #2"
elif grep -q "Assignment #3" $3
then
        echo "$3 Assignment #3"
else
        echo "$3 Assignment #4"
fi

if grep -q "Assignment #1" $4
then
        echo "$4 Assignment #1"
elif grep -q "Assignment #2" $4
then
        echo "$4 Assignment #2"
elif grep -q "Assignment #3" $4
then
        echo "$4 Assignment #3"
else
        echo "$4 Assignment #4"
fi