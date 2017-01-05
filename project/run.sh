#!/bin/bash

make
./roche_limit

# timestamp for clear filenaming
timeStamp="$(date +%Y-%m-%d_%T)_"
# counts lines of gnuplot file -> for loop iterations
lineCounter=$(wc -l < "data/data.dat")-1
# column counter for iterating over all masspoints
columnCounter=$(($(($(awk -F'\t' '{print NF; exit}' data/data.dat)-3))/2)) #grep -m 1 -e '\t' data/data.dat | wc -w

cp include/Constants.h output/${timeStamp}Constants.h

if [ -a "data/output_PNG" ]; then
rm -r "data/output_PNG"
fi
mkdir "data/output_PNG"

# loading GNU Plot scripts
chmod +x bashScripts/*.sh
bashScripts/./plotGIF.sh 'a' $timeStamp $lineCounter $columnCounter     # animated output
#bashScripts/./plotWXT.sh 'a' $timeStamp $lineCounter $columnCounter    # static output ( zoomable )


# plot with: plot for [j=1:10] "data/data.dat" u j*2:j*2+1 w l t sprintf("col: %d", j)
cp data/data.dat output/${timeStamp}gnuPlotData.gplt
#rm -r "data/output_PNG"

exit 0