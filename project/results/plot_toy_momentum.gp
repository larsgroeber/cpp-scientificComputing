#!/bin/gnuplot -p

set terminal pngcairo size 1200,800 enhanced font 'Verdana,20'
set output 'toy_momentum.png'

set style line 8 lc rgb '#f7076f' linetype 1 linewidth 2 # red
set style line 4 lc rgb '#2bb501' linetype 1 linewidth 2 # dark green
set style line 1 lc rgb '#6ca1f7' linetype 1 linewidth 1 # light blue

set xlabel "Time"
set ylabel "Total momentum"

#set xrange [0:25]
#set yrange [0:150]

f(x) = 135

set arrow from 19,graph(0,0) to 19,graph(1,1) nohead ls 1

plot "toy_data.dat" u 1:4 t "Total momentum of the system" w l ls 4 
