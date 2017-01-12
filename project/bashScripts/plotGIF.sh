#!/usr/bin/env bash

# if the first argument is a the variables will be taken from run.sh IF you want to simply make a GIF from the position.dat run without arguments
if [ $1 = 'a' ];
then
    timeStamp=$2
    lineCounter=$3
    columnCounter=$4
    dirVar=''
else
    # timestamp for clear filenaming
    timeStamp="$(date +%Y-%m-%d_%T)_"
    # counts lines of gnuplot file -> for loop iterations
    lineCounter=$(wc -l < "../data/position.dat")-1
    # column counter for iterating over all masspoints
    columnCounter=$(($(($(awk -F'\t' '{print NF; exit}' ../data/position.dat)-3))/2)) #grep -m 1 -e '\t' data/position.dat | wc -w
    dirvar='../'
fi

gnuplot -p <<EOF

########################## GIF ########################## http://www.gnuplotting.org/tag/animation/
reset

## color definitions
set style line 1 lc rgb 'red' lt 1 lw 2 pt 7 ps 2
set style line 2 lc rgb 'blue' lt 1 lw .8 pt 7 ps 2

# graph size
#set xrange [-25:25] #set xrange[-max:max]
#set yrange [-25:25] #set yrange[-max:max]
set size ratio -1

# picture size, etc
set terminal pngcairo size 300,300 enhanced font 'Verdana,10' # comment out for live view instead of gif-outup

# some other interesting terminals  http://www.manpagez.com/info/gnuplot/gnuplot-4.4.0/gnuplot_380.php
#set terminal dumb # ASCII art
#set terminal svg size 350,262 fname 'Verdana' fsize 10
#set output 'output/${timeStamp}output.svg'

n=0
do for [i=1:$lineCounter]{              # adjust loop to MAX_TIME and TIME_STEP from Constants.h

        n=n+1
        # save each step in a png
        set output sprintf("${dirVar}data/output_PNG/simulation%05d.png", n)
#        plot for [j=1:$columnCounter] "${dirVar}data/position.dat" u j*2:j*2+1 w l notitle #t sprintf("col: %d", j)
        plot for [j=1:$columnCounter] '${dirVar}data/position.dat' u j*2:j*2+1 every ::1::i w l notitle #t sprintf("col: %d", j)
#            'data/position.dat' u j*2:j*2+1 every ::i::i w p ls 1 notitle #t "Heavy Object", \
#            'data/position.dat' u j*2:j*2+1 every ::1::i w l ls 1 notitle #t "Heavy Object trace", \
#            'data/position.dat' u j*2:j*2+1 every ::i::i w p ls 2, \    notitle #t "victim", \
#            'data/position.dat' u j*2:j*2+1 every ::1::i w l ls 2       notitle # t "victim trace"
}
#replot
EOF

#convert the png's to a video
#changing -framerate to a higher number will increase the speed of the video # -loop -1 (loops once) -loop 0 (infinty loop)
ffmpeg -framerate 300 -i ${dirVar}data/output_PNG/simulation%05d.png -r 60 -loop -1 "${dirVar}output/${timeStamp}output.gif"  #ffmpeg -framerate 30 -i data/output_PNG/simulation%05d.png -c:v libx264 -vf "fps=25,format=yuv420p" output/output_$(date +%Y-%m-%d_%T).mp4
######################## GIF END ########################

# opening the gif file with standard program    #newestOutputFile="$(ls -d -1 $PWD/**/* -t output/ | head -1)"
xdg-open "${dirVar}output/${timeStamp}output.gif"