#!/bin/gnuplot

set terminal pngcairo size 1200,800 enhanced font 'Verdana,14'

file="hist.dat"

#set xrange [0:10]
set xlabel "Bin"
set ylabel "Mean Counts"

set title "Mean values"
set output "hist_mean.png"

plot file u 1:3 t "Gaussian distribution", file u 1:5 t "Exponential distribution"

set title "Counts"
set output "hist_counts.png"

set ylabel "Counts"

plot file u 1:2 t "Gaussian distribution", file u 1:4 t "Exponential distribution"
