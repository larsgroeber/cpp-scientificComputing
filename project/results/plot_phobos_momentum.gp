#!/bin/gnuplot -p

set terminal pngcairo size 1200,800 enhanced font 'Verdana,20'
set output 'phobos_momentum.png'

set style line 8 lc rgb '#f7076f' linetype 1 linewidth 2 # red 
set style line 4 lc rgb '#2bb501' linetype 1 linewidth 2 # dark green
set style line 1 lc rgb '#6ca1f7' linetype 1 linewidth 1 # light blue

set xlabel "Time"
set ylabel "Momentum"

#set yrange [-36000:-40000]
#set xrange [0:25]

f(x) = 5543

set arrow from 48,graph(0,0) to 48,graph(1,1) nohead ls 1

plot "phobos.dat" u 1:4 t "Total momentum" w l ls 8
