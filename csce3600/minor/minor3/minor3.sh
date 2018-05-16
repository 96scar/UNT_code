#Author: Scarlett Jones
#Euid: srj0101
#ID: 11026836
#email: ScarlettJones@my.unt.edu
#Minor Assignment 3
#Due:2/15/16
#Description: this is a bash script that takes in 1 or 2 arguments to main and does things for certain users
#			  outputs menu options for user to select in a while loop.

#! /bin/bash

#check the number of arguments
if [[ $# == 0 || $# -gt 2 ]]; then #0 arguments or more than 2 arguments is incorrect usage
	echo "usage: minor3 name [euid]"
	exit 1
else
	echo "Good day, $1! Nice to meet you!"	
fi


COUNTER=1 #make variable equal to 1 to start the while loop
while [[ $COUNTER -gt 0 && $COUNTER -lt 4 ]] #if variable is 1,2,or 3, the while loop will continue
do
	echo "+*******************************************************************+
Enter one of the following options:								
1) List and count all non-hidden files in the current directory.	
2) Check if given user (default = current user) is logged in, then 	
... list all active processes for that user.						
3) List the sizes and names of the 10 largest files and directories 
... in the current directory.  										
4) Exit this shell program. 										
+*******************************************************************+"
	read -p "> " COUNTER #reads in the COUNTER variable from menu options for case statement

	case $COUNTER in #uses variable option entered to do certain cases
		1) echo "==> Total number of files: `ls | wc -l`" #backquote prints out number of files on same line as echo
			ls;; #prints out files
		2) if [ $# == 2 ]; then #2 arguments means use specified user
				Log=$(who | grep $2) #check to see if user is logged in
				if [ "$Log" == "" ]; then #if it is 1, they are not logged in
					echo "==> Active processes for $2 (NOT logged in):"
					#processes for specified user not logged in
					ps -ef | grep $2
				else #otherwise, they are logged in
					echo "==> Active processes for $2 (logged in):"
					#processes for specified user logged in
					ps -ef | grep $2
				fi
			else #1 argument means use the default user, which is the current user
				ME=$(whoami) #set variable ME to my username
				echo "==> Active processes for $ME (logged in):"
				#get processes for my username
				ps -ef | grep $ME
			fi;;
		3) echo "==> Size and Name of 10 largest files and directories: "
			du -ac * | sort -n | tail;; # all files with total, sort by number, tail is default 10, no source in front of file/directory (*)
		4) echo "Thanks, $1! Have a great day!"; exit 0;;
		*) echo "Thanks, $1! Have a great day!"; exit 1;;
	esac

done

# 1) list and count all non-hidden files in the current directory
#display total number of non-hidden files in the current directory

# 2) check if given user (default is current user) is logged in, list all active processes for user
#optional euid uses that user as given user, otherwise, use current user
#display if user is logged in, list active processes for user
#grep command can use processes

# 3) list sizes and names of 10 largest files and directories in current directory
#look at the du command pipeliened with other commands

# 4) exit this shell program
#thank you message to user by name, such as "Thanks, Scarlett! Have a great day!
#exits if any option other than 1-3 are entered.
