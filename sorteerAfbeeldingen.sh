#!/usr/bin/env bash
mkdir "$*"/Afbeeldingen

for file in "$*"/*.jpg; do
	echo "Moving $file to ./Afbeeldingen"
	mv $file "$*"/Afbeeldingen/
done

for file in "$*"/*.png; do
        echo "Moving $file to ./Afbeeldingen"
        mv $file "$*"/Afbeeldingen/
done

