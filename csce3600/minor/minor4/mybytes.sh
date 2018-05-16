#! /bin/bash

#Author: Scarlett Jones
#EUID: srj0101
#email: ScarlettJones@my.unt.edu
#ID: 11026836
#Description: prints information about the files in the current directory based on the command line arguments (or lack thereof)

FRX=0 #ordinary, readable, executable files count
nonF=0 #non-existent or other types of files count
D=0 #directories count
FR=0 #ordinary, readable files count
SIZE=0 #total number of bytes in ordinary and readable files

if [ $# == 0 ]; then #if no arguments are given
	files=$(ls -a) #do ls to see all files
	for arg in $files
	do
		if [ -f $arg -a -r $arg -a -x $arg ]; then
			#is ordinary, readable, and executable
			let FRX=FRX+1
		fi
		
		if [ -e $arg ]; then #if it exists, do nothing
			: 
		else
			#is non-existant
			let nonF=nonF+1
		fi		
		
		if [ -d $arg ]; then
			#is a directory
			let D=D+1
		fi			
		
		if [ -f $arg -a -r $arg ]; then
			#is ordinary and readable
			let FR=FR+1
			let SIZE=SIZE+$(stat -c%s $arg)	#tells number of bytes for a specific file	
			#could also have done "let SIZE=SIZE+$(wc -c < $arg)"			
		fi		
	done
elif [ $# -gt 0 ]; then #if arguments are given
	for arg in $@ #take in arguments from command line
	do
		if [ -f $arg -a -r $arg -a -x $arg ]; then
			#is ordinary, readable, and executable
			let FRX=FRX+1
		fi	
		
		if [ -e $arg ]; then #if it exists, do nothing
			:
		else
			#is non-existant
			let nonF=nonF+1
		fi
		
		if [ -d $arg ]; then
			#is a directory
			let D=D+1
		fi			
		
		if [ -f $arg -a -r $arg ]; then
			#is ordinary and readable
			let FR=FR+1
			let SIZE=SIZE+$(stat -c%s $arg)	#tells number of bytes for a specific file		
			#could also have done "let SIZE=SIZE+$(wc -c < $arg)"
		fi			
	done
else #nothing
	:
fi

echo "=============== file data ================"
echo "ordinary, readable, executable files :	$FRX"
echo "non-existant or other types of files :	$nonF"
echo "directory files			     :	$D"
echo "ordinary and readable files	     :	$FR"
echo "total bytes in ordinary files	     :	$SIZE"

