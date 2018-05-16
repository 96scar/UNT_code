#!/bin/bash

COUNT=0

trap 'Set trap on ^C' 2
while true 
do
#echo this is a test

if [ $COUNT -le 2 ]
then
	let COUNT=$COUNT+1
	echo try again
	#trap 'one more time' 2
	#trap - 2
	sleep 2
elif [ $COUNT -eq 3 ]
then 
	trap - 2
	#echo turned off signal trap
else
		echo 
fi

done