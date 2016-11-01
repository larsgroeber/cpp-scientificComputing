#! /bin/bash -e

#### GLOBALS ####

prefix="data_file_00"
suffix=".dat"

#### END GLOBALS ####

echo "Creating files now."

# loop form 0 to 10
for i in {0..10}; do
    # if $i is smaller than 10 we need an extra 0
	if test $i -lt 10; then
		fileName=$prefix"0"$i$suffix
	else
		fileName=$prefix$i$suffix
	fi
    # create file
	touch  $fileName
	echo "Created file $fileName"
done

# ask user to continue
echo "All files were created. Continuing renaming them? [Y/n]"
read a
if test -z $a || test $a == "Y" || test $a == "y"; then 
	echo "Ok, renaming files"	
else
	exit 0
fi

# renaming files: rename EXPRESSION REPLACEMENT FILE...
rename -v _file '' data*.dat

echo "Done"

exit 0
