#!/usr/bin/env bash
DIR=$1

for ((i=2; i <= $#; i++)); do
	COUNT=0
	for file in $DIR/*; do
		if [[ $file == *"${!i}"* ]]; then
			COUNT=$[COUNT+1]
		fi
	done
	echo "Number of files with extension ${!i}: $COUNT"
done
#Ik heb bewust niet voor een case-constructie gekozen, omdat op deze manier het aantal te tellen extensies variabel is
