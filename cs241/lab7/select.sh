# !/usr/bin

# A bash script that displays either the total number of files
# or the total number of directories in the current working directory.
#
# This program pipes the files of the directory into this program where
# the files are filtered down to only files or directories. This is then
# piped out to the wc -l command which will state how many of the specified
# types exist within the current directory.
#
# Note: this is non-recursive
#
# Usage:
#	ls | select [f or d] | wc -l
# 
# Flags:
#	f - only files
#	d - only directories

function filter_files {


	if [ -p /dev/stdin ];
	then
		if [  ${args[0]} = "f" ]
		then
			# only files
			find . -maxdepth 1 -type f -printf '%f\n'	
	
		elif [ ${args[0]} = "d" ]
		then
			find . -mindepth 1 -maxdepth 1 -type d -printf '%f\n'
		fi
	fi
}
	
if [ "$#" -gt 0 ]
then
	args="$@";
	filter_files;
else
	echo "The usage of this command: ls | select [options] | wc -l"
fi
