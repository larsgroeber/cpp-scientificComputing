#!/bin/gnuplot -p

set terminal pngcairo size 1200,800 enhanced font 'Verdana,14'
set output 'access_times.png'

set style line 8 lc rgb '#f7076f' linetype 1 linewidth 2 # red 
set style line 4 lc rgb '#2bb501' linetype 1 linewidth 2 # dark green

d="access_times.dat"

plot d u 1:2 t "Vector", d u 1:3 t "Map", d u 1:4 t "List", d u 1:5 t "Array"
