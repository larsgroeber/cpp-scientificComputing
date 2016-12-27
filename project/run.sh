#!/bin/bash

make
./roche_limit
gnuplot -p <<EOF
#set terminal pngcairo size 800,800 enhanced font 'Verdana,12'
#set output "Orbit.png"

set size square

set xrange [-25:25]
set yrange [-25:25]

plot "data/data.dat" u 2:3 w l, "data/data.dat" u 4:5 w l
EOF

#feh Orbit.png

exit 0
