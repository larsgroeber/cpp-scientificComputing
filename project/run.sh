#!/bin/bash

make
./roche_limit

# the argument for the run.sh -> to un gif or mp4 or else...
runArgument=$1
# timestamp for clear filenaming
timeStamp="$(date +%Y-%m-%d_%T)_"
# counts lines of gnuplot file -> for loop iterations
lineCounter=$(wc -l < "data/position.dat")-1
# column counter for iterating over all masspoints
columnCounter=$(($(($(awk -F'\t' '{print NF; exit}' data/position.dat)-3))/2)) #grep -m 1 -e '\t' data/position.dat | wc -w

cp include/Constants.h output/${timeStamp}Constants.h

if [ -a "data/output_PNG" ]; then
rm -r "data/output_PNG"
fi
mkdir "data/output_PNG"

# loading GNU Plot scripts
chmod +x bashScripts/*.sh

case $1 in
'gif')
bashScripts/plotGIF.sh 'a' $timeStamp $lineCounter $columnCounter     # animated output
   ;;
'mp4')
bashScripts/plotMP4.sh 'a' $timeStamp $lineCounter $columnCounter     # animated output
   ;;
*)
bashScripts/plotWXT.sh 'a' $timeStamp $lineCounter $columnCounter    # static output ( zoomable )
;;
esac


# plot with: plot for [j=1:10] "data/position.dat" u j*2:j*2+1 w l t sprintf("col: %d", j)
cp data/position.dat output/${timeStamp}gnuPlotData.gplt
#rm -r "data/output_PNG"

exit 0