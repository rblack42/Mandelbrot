// Copyright 2018 Roie R. Black
#include <iostream>
#include <cstring>

#include "version.h"
#include "Graphics.h"

// main application runner
int main(int argc, char * argv[]) {
    // say hello
    std::cout
        <<  "Mandelbrot Explorer"
        << "(" << VERSION << ")\n";
    // start the real application
    Graphics app;
    app.glut_init(argc, argv);      // start the graphics engine
    app.start();                    // and begin generating images
    return 0;
}

