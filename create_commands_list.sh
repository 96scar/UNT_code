#!/bin/bash

rm cmds.txt
rm cmds_description.txt
rm real_cmds.txt

compgen -A function -abck | sort -u > cmds.txt

while read -r line
do
CMD=$( whatis $line | 
      awk '{ print $2, $3 }' )
if [[ "$CMD" != "nothing appropriate" ]]
then
	whatis $line >> cmds_description.txt
	echo $line >> real_cmds.txt
fi

done < cmds.txt
