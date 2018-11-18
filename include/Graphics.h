// COpyright 2018 ROie R> Black
// Graphics.h - Base Graphics class - subclass for application
#pragma once

// graphics included for GLUT based braphics projects
#if defined __APPLE__
    #include <OpenGL/gl.h>
    #include <GLUT/glut.h>
#elif defined(__linux__)
    #include <GL/glut.h>
#elif defined(_WIN32)
    #include <GL/glut.h>
#endif

#include "Timer.h"
#include "Mandelbrot.h"

// graphics library tools

class Graphics {
 protected:
    static Graphics * instance;
    static int frames;
    Timer timer;
    double elapsed_time;
    Mandelbrot fractal;

 public:
    // window constants
    static const int WINDOW_WIDTH = 800;    // initial window width
    static const int WINDOW_HEIGHT = 600;   // intiial window height
    static const int WINDOW_X = 50;         // initial window x position
    static const int WINDOW_Y = 50;         // initial window y position

    static const int FPS = 60;              // desired frame rate
    static const double FRAME_MSEC;         // calculated from FPS

 public:
    // default constructor
    Graphics();

    // start graphics application
    void start(void);

    // initialize GLUT
    void glut_init(int argc, char * argv[]);

    // helper routines
    void setInstance();
    void animate();
    void display();
    void keyboard(unsigned char key, int x, int y);
    void glutMouseFunc(int button, int state, int x, int y);
    void mouseButton(int button, int state, int x, int y);
    void specialKeyboard(int key, int x, int y);
    // void mouseClicks(int button, int state, int x, int y);
    void reCenter(int x, int y);

    // static callback methods for GLUT
    static void displayWrapper();
    static void keyboardWrapper(unsigned char key, int x, int y);
    static void specialKeyboardWrapper(int key, int x, int y);
    static void mouseButtonWrapper(int button, int state, int x, int y);
    static void glutMouseFuncWrapper(int button, int state, int x, int y);
    static void animateWrapper();
    static void reCenterWrapper(int x, int y);
};
