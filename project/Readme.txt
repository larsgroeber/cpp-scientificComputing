Readme

This Project simulates a roche limit problem. There are 3 Problems that you can use but you can also change the
code to add more examples. You can either get an image, a GIF, mp4 or an openGL animation.

in order to run the openGL simulation you need these libraries: jaogll which uses the libraries SDL2, GLM and GLEW
after you installed the libraries you can run the simulation with "make graphic"

for all other outputs you need to install the library ffmpeg.
you can create a GIF, a mp4 or an image by running "./run.sh gif" or "./run.sh mp4" or "./run.sh image"

here is a list of all files and folders with a short description:
.
├── bashScripts             the different gnuPlot scripts are in this folder
│   ├── plotGIF.sh          outputs a GIF
│   ├── plotMP4.sh          outputs a mp4
│   └── plotWXT.sh          outputs an image
├── graphics                this folder contains the OpenGL animation code
│   ├── black-circle.png    the picture that represents all planets or asteroid particles
│   ├── graphic.cpp
│   ├── graphic.h
│   ├── README.md
├── helper                  this folder includes some classes that are useful for this project
│   ├── include
│   │   ├── IOManager.h
│   │   └── Vector.h
│   └── src
│       ├── IOManager.cpp   this class is used to write files
│       └── Vector.cpp      this class implements a 2 dimensional vector useful for 2d graphics
├── include
│   ├── Body.h
│   ├── Constants.h
│   └── Simulation.h
├── main.cpp                the actual main.cpp is very small (the main part is found in Simulation.cpp)
├── makefile                "make" is used by run.sh if you want to run the openGL version run "make graphic"
├── results                 contains some results created with this code
├── run.sh                  to create a GIF, mp4 or an image run "./run.sh gif" (replace "gif" with "mp4" or "image")
└── src
    └── Simulation.cpp      this is the actual Simulation code