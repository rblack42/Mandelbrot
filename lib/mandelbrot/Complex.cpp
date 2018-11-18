// Copyright 2018 Roie R. Black
#include "Complex.h"
#include <sstream>
#include <cmath>

// constructors
Complex::Complex() {
    real = 0.0;
    imaginary = 0.0;
}

Complex::Complex(double r, double i) {
    real = r;
    imaginary = i;
}

// accessors
double Complex::get_real(void) {
    return real;
}

double Complex::get_imaginary(void) {
    return imaginary;
}

double Complex::get_magnitude(void) {
    double temp = real * real + imaginary * imaginary;
    return sqrt(temp);
}

// operators
Complex Complex::operator + (const Complex & rhs) {
    Complex temp;
    temp.real = real + rhs.real;
    temp.imaginary = imaginary + rhs.imaginary;
    return temp;
}

Complex Complex::operator - (const Complex & rhs) {
    Complex temp;
    temp.real = real - rhs.real;
    temp.imaginary = imaginary - rhs.imaginary;
    return temp;
}

Complex Complex::operator * (const Complex & rhs) {
    Complex temp;
    temp.real = real * rhs.real - imaginary * rhs.imaginary;
    temp.imaginary = real * rhs.imaginary + imaginary * rhs.real;
    return temp;
}

Complex Complex::operator / (const Complex & rhs) {
    Complex temp;
    double demon = rhs.real*rhs.real + rhs.imaginary*rhs.imaginary;
    temp.real = (real * rhs.real + imaginary * rhs.imaginary) / demon;
    temp.imaginary = (- real * rhs.imaginary + imaginary * rhs.real)/demon;
    return temp;
}

std::string Complex::toString(void) {
    std::ostringstream temp;
    temp << real << "+" << imaginary << "i";
    return temp.str();
}
