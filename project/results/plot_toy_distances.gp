#!/bin/gnuplot -p

set terminal pngcairo size 1200,800 enhanced font 'Verdana,14'
set output 'toy_distances.png'

set style line 8 lc rgb '#f7076f' linetype 1 linewidth 2 # red 
set style line 4 lc rgb '#2bb501' linetype 1 linewidth 2 # dark green
set style line 1 lc rgb '#6ca1f7' linetype 1 linewidth 1 # light blue

set xlabel "Time"
set ylabel "Distance"

set xrange [0:25]

f(x) = 135

plot "toy_data.dat" u 1:2 t "Distance of one mass point to the planet" w l ls 4, "toy_data.dat" u 1:3 t "Average internal distance" w l ls 8, f(x) t "Roche Limit" w l ls 1
