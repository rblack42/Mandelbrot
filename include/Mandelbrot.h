// Copyright 2018 Roie R. Black
// Mandelbrot.h - generate Mandelbrot image
#pragma once
#include "Complex.h"

class Mandelbrot {
 public:
    int IMAGE_WIDTH;
    int IMAGE_HEIGHT;
    unsigned char * bitmap;

    // zone controls
    double xMax;
    double xMin;
    double yMax;
    double yMin;

    // positioning controls
    double xOff;
    double yOff;
    double scale;

    double pixelHeight;
    double pixelWidth;
    int max_iterations;

    // defaut constructor
    Mandelbrot();
    void init(int w, int h);
    void reset(void);
    int pixelValue(double x, double y);
    void initBitmap();
    unsigned char *  generate(void);
};
