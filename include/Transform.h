// Copyright 2018 Roie R. Black
#pragma once

class Transform {
 public:
    // constructor
    Transform();
    Transform(double x, double y, double s);

    // accessors
    double xc_to_xg(double n);
    double yc_to_yg(double n);
    double xg_to_xc(double n);
    double yg_to_yc(double n);

    // mutators
    void set_translate(double xv, double yv);
    void set_scale(double sf);

 private:
    double xt;  // translate in X direction
    double yt;  // translate in Y direction
    double sf;  // scale coordinates
};
