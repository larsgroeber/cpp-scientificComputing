#! /bin/bash -e

prefix="data_file_00"
suffix=".dat"

echo "Creating files now."

for i in {0..10}; do
	if test $i -lt 10; then
		fileName=$prefix"0"$i$suffix
	else
		fileName=$prefix$i$suffix
	fi
	touch  $fileName
	echo "Created file $fileName"
done

echo "All files were created. Continuing renaming them? [Y/n]"
read a
if test -z $a || test $a == "Y" || test $a == "y"; then 
	echo "Ok, renaming files"	
else
	exit 0
fi

rename -v _file '' data*.dat

echo "Done"

exit 0
