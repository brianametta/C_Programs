#!/bin/bash

echo "Assignment #2-2, Briana Wright, masc1429"

for file in $(grep -lr 'include' $1/*); do
        cp $file $(basename ${file}).c
        echo $(basename ${file}).c
done