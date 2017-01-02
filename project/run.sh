#!/bin/bash

make
./roche_limit
gnuplot -p <<EOF
#set terminal pngcairo size 800,800 enhanced font 'Verdana,12'
#set output "Orbit.png"

#set size square

#set xrange [-25:25]
#set yrange [-25:25]

#plot "data/data.dat" u 2:3 w l, "data/data.dat" u 4:5 w l

########################## GIF ##########################
####################### attempts ########################
# color definitions
#set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 2 # --- blue
#set terminal gif animate delay 100

#do for [i=1:1000] {
#    plot 'data/data.dat' index (i-1) with circles
#}

#do for [ii=1:1000] {
#    splot "data/data.dat" u 2:3 every w l, \
#          "data/data.dat" u 4:5 every w l
#}

#for ((i=2; i<21; i++)); do echo -e "set yrange [-25:25];pl i*sin(x) \n"; done | gnuplot -persist   # works on shell
##################### attempts END ######################
# http://www.gnuplotting.org/tag/animation/
reset
## color definitions
set style line 1 lc rgb 'red' lt 1 lw 1 pt 7 ps 2
set style line 2 lc rgb 'blue' lt 1 lw .1 pt 7 ps 2

#set size square
#set xrange [-25:25]
#set yrange [-25:25]

#set xrange[min:max]
#set yrange[min:max]
set size ratio -1

do for [i=2:1000] {
#        set output sprintf('png/spiral%03.0f.png',n)
    plot 'data/data.dat' u 2:3 every ::i::i w p ls 1 t "Heavy Object", \
         'data/data.dat' u 2:3 every ::1::i w l ls 1 t "Heavy Object trace", \
         'data/data.dat' u 4:5 every ::i::i w p ls 2 t "victim", \
         'data/data.dat' u 4:5 every ::1::i w l ls 2 t "victim trace"
}
######################## GIF END ########################

EOF

#feh Orbit.png

exit 0