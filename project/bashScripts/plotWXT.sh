#!/usr/bin/env bash

timeStamp=$1
lineCounter=$2
columnCounter=$3

gnuplot -p <<EOF
reset

## color definitions
set style line 1 lc rgb 'red' lt 1 lw 2 pt 7 ps 2
set style line 2 lc rgb 'blue' lt 1 lw .8 pt 7 ps 2

# graph size
#set xrange [-25:25] #set xrange[-max:max]
#set yrange [-25:25] #set yrange[-max:max]
set size ratio 1

# picture size, etc
#set term x11
set term wxt # unstable
# some other interesting terminals  http://www.manpagez.com/info/gnuplot/gnuplot-4.4.0/gnuplot_380.php
#set terminal dumb # ASCII art

plot for [j=1:$columnCounter] "data/position.dat" u j*2:j*2+1 w l notitle #t "test"# sprintf("col: %d", j)

#replot
EOF