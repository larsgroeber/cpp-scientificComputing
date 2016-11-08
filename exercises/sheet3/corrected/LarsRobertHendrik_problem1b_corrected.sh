#! /bin/bash -e

#################################################
#	Comments by Bulcsu Sandor: "# BS: "
#	Points: 3/3
#################################################

# uses bash for easier control over variables and messages

# check if file was given by parameter
if test ! -z $1; then
	inputFile=$1
else
    # otherwise use default one
	inputFile="matrix.dat"
fi

# check if file exists
if test ! -e $inputFile && test ! -r $inputFile; then
	echo "File $inputFile does not exist or is not readable!" >&2
	exit 1
fi

echo "Press <ENTER> to continue after one operation."
# BS: the Enter was a good idea

# print the inputfile
echo "This is the inputFile:"
awk ' { print $0 }' $inputFile
read

# mean value of each line
echo "Computing the mean value for each line."
# NF returns the number of fields
awk '{ print ($1+$2+$3+$4+$5)/NF }' $inputFile
read

# mean value if first column
echo "Computing the mean value for the first column."
# NR returns the row-number
awk '{ total=total+$1 } END { print total/NR }' $inputFile
read

# rows with mean value of >= 1 and <= 50
echo "Printing only rows with a mean value of >= 1 and <= 50."
awk '{ mean=($1+$2+$3+$4+$5)/NF; if ( mean >= 1 && mean <= 50 ) \
	print "Line "NR", mean "mean":\t" $0 }' $inputFile
read

# calculating trace
echo "Printing the trace."
# BS: this is a nice one!
awk '{ total=total+$NR } END { print total }' $inputFile

exit 0
