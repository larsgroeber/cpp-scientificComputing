#!/bin/bash

make
./test.out
gnuplot -p <<EOF
set xrange [-25:25]
set yrange [-25:25]

plot "test.dat" u 2:3 w l
EOF
