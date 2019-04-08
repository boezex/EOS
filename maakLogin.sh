#!/usr/bin/env bash
echo "Please enter desired username: "
read username
if [[ -z $username ]]; then
	$username = $USER
fi
pwd1=""
pwd2=""
while [[ ${#pwd1} -le 8 ]] && [[ $pwd1 != $pwd2 ]] && [[ ! $pwd1 =~ [A-Z] ]] && [[ ! $pwd1 =~ '^[0-9]+$' ]]; do
	echo "Please enter desired password (=> 8 characters, minimum 1 capital letter and 1 number): "
	read $pwd1
	echo "Please repeat password: "
	read $pwd2
done

echo "$username, $pwd1, $pwd2"

