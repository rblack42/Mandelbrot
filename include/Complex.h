// Copyright 2018 Roie R. Black
#pragma once
#include <string>

class Complex {
 public:
     Complex();
     Complex(double r, double i);

     // accessors
     double get_real(void);
     double get_imaginary(void);
     double get_magnitude(void);
     std::string toString();

     // operators
     Complex operator + (const Complex & rhs);
     Complex operator - (const Complex & rhs);
     Complex operator * (const Complex & rhs);
     Complex operator / (const Complex & rhs);

 private:
     double real;
     double imaginary;
};
