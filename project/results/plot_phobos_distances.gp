#!/bin/gnuplot -p

set terminal pngcairo size 1200,800 enhanced font 'Verdana,14'
set output 'phobos_distances.png'

set style line 8 lc rgb '#f7076f' linetype 1 linewidth 2 # red 
set style line 4 lc rgb '#2bb501' linetype 1 linewidth 2 # dark green
set style line 1 lc rgb '#6ca1f7' linetype 1 linewidth 1 # light blue

set xlabel "Time"
set ylabel "Distance"

set yrange [950:1020]
set xrange [20:60]

f(x) = 5543

set arrow from 48,graph(0,0) to 48,graph(1,1) nohead ls 1

plot "phobos.dat" u 1:3 t "Average internal distance" w l ls 8
