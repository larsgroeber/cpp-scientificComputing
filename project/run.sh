#!/bin/bash

make
./roche_limit

#for testing:
#gnuplot -p <<EOF
#set size ratio -1
##set terminal wxt size 950,950
#set style line 1 lc rgb 'red' lt 1 lw .1 pt 7 ps .4
#plot 'data/BodyCloud.gplt' u 1:2 w p ls 1, 'data/BodyCloud.gplt' u 1:2 w l ls 1
#EOF

mkdir "data/output_PNG"

timeStamp="$(date +%Y-%m-%d_%T)_"
# counts lines of gnuplot file -> loop iterations
lineCounter=$(wc -l < "data/data.dat")-1

gnuplot -p <<EOF
########################## OLD ##########################
#set size square
#plot "data/data.dat" u 2:3 w l, "data/data.dat" u 4:5 w l
######################## OLD END ########################

########################## GIF ########################## http://www.gnuplotting.org/tag/animation/
reset

## color definitions
set style line 1 lc rgb 'red' lt 1 lw 2 pt 7 ps 2
set style line 2 lc rgb 'blue' lt 1 lw .8 pt 7 ps 2

# graph size
#set xrange [-25:25] #set xrange[-max:max]
#set yrange [-25:25] #set yrange[-max:max]
#set size ratio -1

# picture size, etc
set terminal pngcairo size 300,300 enhanced font 'Verdana,10' # comment out for live view instead of gif-outup

n=0
do for [i=1:$lineCounter] {             # adjust loop to MAX_TIME and TIME_STEP from Constants.h
        n=n+1
        # save each step in a png
        set output sprintf("data/output_PNG/simulation%05d.png", n)
    plot 'data/data.dat' u 2:3 every ::i::i w p ls 1 t "Heavy Object", \
         'data/data.dat' u 2:3 every ::1::i w l ls 1 t "Heavy Object trace", \
         'data/data.dat' u 4:5 every ::i::i w p ls 2 t "victim", \
         'data/data.dat' u 4:5 every ::1::i w l ls 2 t "victim trace"
}
#replot
EOF

#convert the png's to a video
#changing -framerate to a higher number will increase the speed of the video # -loop -1 (loops once) -loop 0 (infinty loop)
ffmpeg -framerate 300 -i data/output_PNG/simulation%05d.png -r 60 -loop -1 "output/${timeStamp}output.gif"
#ffmpeg -framerate 30 -i data/output_PNG/simulation%05d.png -c:v libx264 -vf "fps=25,format=yuv420p" output/output_$(date +%Y-%m-%d_%T).mp4
######################## GIF END ########################

mv data/data.dat output/${timeStamp}gnuPlotData.gplt
cp helper/include/Constants.h output/${timeStamp}Constants.h
rm -r "data/output_PNG"

# opening the gif file with standard program
#newestOutputFile="$(ls -d -1 $PWD/**/* -t output/ | head -1)"
xdg-open "output/${timeStamp}output.gif"

exit 0