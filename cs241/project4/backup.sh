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
#	--help: display a help menu
#
# @author Ron Rounsifer

# List all of the files currently in the ~/.backup directory
function list_files {

	# list the files in the ~/.backup directory if it exists	
	if [ -e ~/.backup ]
	then
		ls -la ~/.backup;
	else
		echo "There are currently no backups present at this time."
	fi
}


# Display information on the .backup directory if it exists
# Info includes:
#	1) number of files
#	2) size of the files (bytes) and the files absolute path
function file_data {
	cwd="$(pwd)";

	if [ -e ~/.backup ]
	then
		cd ~/.backup;
		num_files="$(ls . | wc -l)";
		echo "=================================================================";
		echo "Number of files in ~/.backup: ${num_files}";
		echo "";
		echo "";
		echo "The storage consumed by ~/.backup is:";
		
		# for each file, print its size and absolute path
		for i in ~/.backup/*;
		do 
			file_size="$(wc -c $i)";
			echo "${file_size}"
		done
		echo "=================================================================";	
	else
		echo "There are currently no backups present at this time."
	fi
}

# Display the help menu to the user
function help_user {
	echo "=================================================================";
	echo "backup usage: backup [options] source-files";
	echo "Backup files/directories in source-files to ~/.backup.";
	echo "-l: list files in ~/.backup";
	echo "-n: display the number of files and the storage they consume";
	echo "-h or --help: display this menu";
	echo "=================================================================";
}


# Runs through the files passed as arguments to the backup call.
# For each file passed, it attempts to copy the file to the backup folder.
function backup_files {

	help_menu='0';
	for file in $args;
	do
		if [ -e ./$file ]
		then
			# make sure the backup dir exists before adding files
			if [ ! -d  ~/.backup ]
			then
				mkdir ~/.backup;
			fi
			
			# if the file already exists, keep the newer one
			if [ -e ~/.backup/$file ]
			then			
				local_file_last_mod="$(stat $file -c %Y)";
				backup_file_last_mod="$(stat ~/.backup/$file -c %Y)";	
				
				if [ $local_file_last_mod -lt $backup_file_last_mod ]	
				then
					rm -rf ~/.backup/$file;
					cp -r ./$file ~/.backup;
				fi
			else	
				cp -r ./$file ~/.backup;
			fi	
		fi
	done
	
	if [ $display_help -gt 0 ]
	then
		help_user
	fi

}


display_help='0'

# Control flow for options if any entered
# Since getopts does not handle long options, a pseudo-long-option
# is created by making the '-' option require arguments, which will
# be 'help' in this case.
while getopts 'ln-:' flag; do
	case "${flag}" in 
		l) list_files;;
		n) file_data;;
		-) LONG_OPTARG="${OPTARG#*=}"
		   case $OPTARG in 
			help) display_help='1';;
			*) break;;
		   esac;;
		*) break;;
	esac
done

# Backup the files in the directory
if [ "$#" -gt 0 ] 
then
	args="$@";
	backup_files;
fi
