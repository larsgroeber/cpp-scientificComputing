#!/bin/bash

#run this an hopefully it will do everything automatically

# Compile main.cpp
g++ rec.cpp

# Pipe output into file
results_triangle_map.dat << ./a.out

# Plot data
gnuplot -p <<EOF
    plot 'results_triangle_map.dat'
EOF

exit 0
