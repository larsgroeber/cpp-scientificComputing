Readme

This Project simulates a roche limit problem. There are 3 examples that you can use. You can either get an image, a GIF, mp4 or an openGL animation.

In order to run the openGL simulation you need these libraries: jaogll which uses the libraries SDL2, GLM and GLEW after you installed the libraries you can run the simulation with "make graphic"
you can zoom in/out with "Q" and "E"
CAUTION: You need to comment in "#define GRAPHICS" in Constants.h and comment out "#define POS_DATA"

For all other outputs you need to install the library ffmpeg.
You can create a GIF, a mp4 or an image by running "./run.sh gif" or "./run.sh mp4" or "./run.sh image"
CAUTION: You need to comment in "#define POS_DATA" in Constants.h and comment out "#define GRAPHICS"



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
│   ├── Body.h              defines a body struct (all planets and asteroid particles are bodies)
│   ├── Constants.h         includes all constants like the gravitational constant, masses, radii
│   └── Simulation.h        this is the actual Simulation code
├── main.cpp                the actual main.cpp is very small (the main part is found in Simulation.cpp)
├── makefile                "make" is used by run.sh if you want to run the openGL version run "make graphic"
├── results                 contains some results created with this code
├── run.sh                  to create a GIF, mp4 or an image run "./run.sh gif" (replace "gif" with "mp4" or "image")
└── src
    └── Simulation.cpp