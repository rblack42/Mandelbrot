// Graphics.cpp - Simple graphics library for COSC students
// Copyright 2018 Roie R. Black
#include <iostream>
#include "Graphics.h"
#include "Timer.h"

// class variables ------------------------------------------------------------
const double Graphics::FRAME_MSEC = 1.0 / Graphics::FPS * 1000.0;  // millisecs
Graphics * Graphics::instance = NULL;
int Graphics::frames = 0;

// default constructor --------------------------------------------------------
Graphics::Graphics() {
    elapsed_time = 0;
    fractal.init(WINDOW_WIDTH, WINDOW_HEIGHT);
    fractal.initBitmap();
}

// start the graphics application ---------------------------------------------
void Graphics::start(void) {
    std::cout << "GLUT app running" << std::endl;
    std::cout << "  framerate = " << FPS;
    std::cout << " (" << FRAME_MSEC << " msecs/frame)" << std::endl;
}

void Graphics::glut_init(int argc, char * argv[]) {
    setInstance();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(WINDOW_X, WINDOW_Y);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Mandlebrot Explorer");

    glutDisplayFunc(displayWrapper);
    glutKeyboardFunc(keyboardWrapper);
    ::glutMouseFunc(mouseButtonWrapper);
    glutSpecialFunc(specialKeyboardWrapper);
    glutIdleFunc(animateWrapper);
    glutMainLoop();
}

// helper functions
void Graphics::setInstance() {
    instance = this;
}

// GLUT display methods -------------------------------------------------------
void Graphics::display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    unsigned char * buffer = fractal.generate();
    glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA,
                    GL_UNSIGNED_BYTE, buffer);
    ++frames;
    glutSwapBuffers();
}

void Graphics::displayWrapper() {
    instance->display();
}

// animation method -----------------------------------------------------------

void Graphics::animateWrapper() {
    instance->animate();
}

void Graphics::animate() {
    if (!timer.running()) {
        timer.start();
    }
    timer.stop();
    double milliseconds = timer.get_elapsed_time();
    elapsed_time += FRAME_MSEC;
    if (elapsed_time >= FRAME_MSEC) {
        glutPostRedisplay();
        elapsed_time -= FRAME_MSEC;
    }
    timer.start();
}

// keyboard handler code ------------------------------------------------------

void Graphics::keyboard(unsigned char key, int x, int y) {
    std::cout << "key = " << key << std::endl;
    if (key == 27  || key == 'q') {
        std::cout << "Application terminated:" << std::endl;
        std::cout << "  frames: " << frames << std::endl;
        exit(0);
    }
    if (key == 'r') {
        fractal.reset();
    }
}

void Graphics::keyboardWrapper(unsigned char key, int x, int y) {
    instance->keyboard(key, x, y);
}

// special keyboard handler ---------------------------------------------------

void Graphics::specialKeyboard(int key, int x, int y) {
    std::cout << "special key = " << key << std::endl;
    if (key == GLUT_KEY_UP) fractal.yOff -= 1;
    if (key == GLUT_KEY_DOWN) fractal.yOff += 1;
    if (key == GLUT_KEY_RIGHT) fractal.xOff -= 1;
    if (key == GLUT_KEY_LEFT) fractal.xOff +=1;
    if (key == GLUT_KEY_F5) fractal.scale *=1.1;
    if (key == GLUT_KEY_F6) fractal.scale *=0.9;
}

void Graphics::specialKeyboardWrapper(int key, int x, int y) {
    instance-> specialKeyboard(key, x, y);
}

void Graphics::mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        std::cout
            << "Click detected at: X "
            <<  x << ", Y "
            << y << std::endl;
        fractal.xOff -= (400 - x) * fractal.pixelWidth; 
        fractal.yOff -= (300 - y) * fractal.pixelHeight; 
}


void Graphics::mouseButtonWrapper(int button, int state, int x, int y) {
    instance -> mouseButton(button, state, x, y);
}
