# !/usr/bin
# Bash script that will read in class IDs and projects before
# creating sub-directories for each class that holds a sub-directory
# of the project specified in the data.

function create_directories {
	while read -r line;do
		line=( $line )
		class=${line[0]}
		project=${line[1]}
		
		# Create top most directory if it doesn't exist
		if [ ! -d ./$class ]
		then
			mkdir ./$class;
			
			if [ ! -d ./$class/$project ]
			then
				touch ./$class/$project;
			fi
		else
			if  [ ! -d ./$class/$project ]
			then
				touch ./$class/$project;
			fi
		fi		
		
	done < $filename;
}

if [ "$#" -eq 1 ]
then
	filename="$1"
	create_directories;
else
	echo "The usage of this command is: readfile [filename]"
fi
