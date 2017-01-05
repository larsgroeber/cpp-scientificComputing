#!/usr/bin/env bash

gnuplot -p <<EOF
set size ratio -1
#set terminal wxt size 950,950
set style line 1 lc rgb 'red' lt 1 lw .1 pt 7 ps .4
plot 'data/BodyCloud.gplt' u 1:2 w p ls 1, 'data/BodyCloud.gplt' u 1:2 w l ls 1
EOF