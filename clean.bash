#!/bin/bash
# @file clean
# @author Arya Nguyen
# @brief delete all files and folder in .gitignore in current folder and all subfolder

dir="."
folderToRemove=( )
extToRemove=( )
subfolder=true

# get arguments
while getopts "f:n" opt; do
	case $opt in 
		f) 
			dir=$OPTARG
			;;
		n) 
			subfolder=false
			;;
		?) 
			echo "usage: $0 [-f arg]" [-nosub]; 
			exit 1
			;;
	esac
done

# check if dir exists; otherwise warning and exits
if [ ! -e "$dir" ]; then
	echo -e "ERROR: $dir not found" 
	exit 1	
fi


# get from stdin list of files to 
function getGitignoreFiles() 
{
	while read line; do
		if [[ "${line:0:1}" != "#" ]]; then  # ignore comment
			# echo ${line}
			if [[ ${line:0:1} == "*" ]]; then
				len="$((${#line} - 1))"
				extToRemove+=( ${line: -$len} ) 
				# echo $extToRemove
			else 
				folderToRemove+=( ${line} ) 
			fi
		fi
	done < "${1:-/dev/stdin}"
}


# Recursively check subdir and delete all  
function checkAndRemove()
{	
	# loop through all files and folder including hidden ones
	for f in $1/{..?,.[!.],}*; do
	
		# loop through needToBeRemoved files
		for r in "${folderToRemove[@]}"; do 
			# check if matching toBeRemoved files 
			# echo $f   -   $r
			if [[ "${f##*/}" == "$r" ]]; then
				echo "Remove Folder: $f"  # notify deleted folder
				rm -r $f  # remove folder
			fi
		done

		# remove extension
		for r in "${extToRemove[@]}"; do 
			# check if matching toBeRemoved files 
			# echo $f   -   $r
			len=${#r}
			if [ "${f: -$len}" == "$r" ]; then
				echo "Remove Extension: $f"  # notify deleted folder
				rm $f  # remove folder
			fi
		done

		# check of is a folder, then do recursive to remove 
		if $subfolder && [ -d "$f" ]; then
			checkAndRemove $f
		fi
	done
}

# call function
getGitignoreFiles
checkAndRemove "$dir"

