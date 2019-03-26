#!/bin/bash
#
# A bash script that will allow the user to backup files and directories that
# are passed as arguments to the location of '~/.backup/'.
#
# Options: 
#	-l: list all of the files in the backup directory
#	
#	-n: shows the number of files in the directory and how much memory 
#	    these files are allocated
#	
#	-h: display a help menu
#
# @author Ron Rounsifer

# FUNCTIONS
function list_files {
	echo "-l passed";
	echo "list backed up files here";
}

function file_data {
	echo "-n passed";
	echo "list off data here";
}

function help_user {
	echo "=================================================================";
	echo "backup usage: backup [options] source-files";
	echo "Backup files/directories in source-files to ~/.backup.";
	echo "-l: list files in ~/.backup";
	echo "-n: display the number of files and the storage they consume";
	echo "-h | --help: display this menu";
	echo "=================================================================";
}


while getopts 'lnh' flag; do
	case "${flag}" in 
		h) help_user;;
		l) list_files;;
		n) file_data;;
		*) break;;
	esac
done

