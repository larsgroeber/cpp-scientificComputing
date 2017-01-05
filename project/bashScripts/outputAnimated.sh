#!/usr/bin/env bash

n=0
do for [i=1:$lineCounter] {             # adjust loop to MAX_TIME and TIME_STEP from Constants.h
        n=n+1
        # save each step in a png
        set output sprintf("data/output_PNG/simulation%05d.png", n)
#    plot for [j=1:$columnCounter] "data/data.dat" u j*2:j*2+1 w l t sprintf("col: %d", j)
    plot for [j=1:$columnCounter] \
        'data/data.dat' u j:j+1 every ::i::i w p ls 1 t "Heavy Object", \
        'data/data.dat' u j:j+1 every ::1::i w l ls 1 t "Heavy Object trace", \
        'data/data.dat' u j:j+1 every ::i::i w p ls 2 t "victim", \
        'data/data.dat' u j:j+1 every ::1::i w l ls 2 t "victim trace"
}
#replot