#!/usr/bin/env bash
mkdir "$*"/Afbeeldingen/Vakantie

for file in $(find "$*"/Afbeeldingen -name 'vakantie-*' | grep -o vakantie.*); do
	echo "$file"
	mv "$*"/Afbeeldingen/"$file" "$*"/Afbeeldingen/Vakantie/"$file"
done
