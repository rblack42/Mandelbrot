// Copyright 2018 Roie R. Black
#include "Transform.h"

// constructor
Transform::Transform() {
    sf = 1.0;
    xt = 0.0;
    yt = 0.0;
}

Transform::Transform(double x, double y, double s) {
    sf = s;
    xt = x;
    yt = y;
}

// accessors
double Transform::xc_to_xg(double n) {
    return n * sf + xt;
}

double Transform::yc_to_yg(double n) {
    return n * sf + yt;
}

double Transform::xg_to_xc(double n) {
    return (n - xt) / sf;
}

double Transform::yg_to_yc(double n) {
    return (n - yt) / sf;
}

// mutators
void Transform::set_translate(double xv, double yv) {
    xt = xv;
    yt = yv;
}

void Transform::set_scale(double v) {
    sf = v;
}
