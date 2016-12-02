#!/bin/bash

# Compile main.cpp
g++ main.cpp

# Pipe output into file
./a.out

# Plot data
gnuplot -p <<EOF
    plot 'cpp_data.dat'
EOF

exit 0
