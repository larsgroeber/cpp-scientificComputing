#!/usr/bin/env bash

plot for [j=1:$columnCounter] "data/position.dat" u j*2:j*2+1 w l t sprintf("col: %d", j)

#replot