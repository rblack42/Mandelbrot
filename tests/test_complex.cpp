#include <catch.hpp>
#include "Complex.h"

TEST_CASE( "test complex class constructor" ) {
    Complex c(5.0,3.0);
    REQUIRE(c.get_real() == 5.0);
    REQUIRE(c.get_imaginary() == 3.0);
}

TEST_CASE( "test complex class add operator" ) {
    Complex a(1.0,2.0);
    Complex b(3.0,4.0);
    Complex c = a + b;
    REQUIRE(c.get_real() == 4.0);
    REQUIRE(c.get_imaginary() == 6.0);
}

TEST_CASE( "test complex class subtract operator" ) {
    Complex a(3.0,4.0);
    Complex b(1.0,2.0);
    Complex c = a - b;
    REQUIRE(c.get_real() == 2.0);
    REQUIRE(c.get_imaginary() == 2.0);

}

TEST_CASE( "test complex class multiply operator" ) {
    Complex a(3.0,2.0);
    Complex b(1.0,4.0);
    Complex c = a * b;
    REQUIRE(c.get_real() == -5.0);
    REQUIRE(c.get_imaginary() == 14.0);
}

TEST_CASE( "test complex class division operator" ) {
    Complex a(3.0,5.0);
    Complex b(2.0,4.0);
    Complex c = a / b;
    REQUIRE(c.get_real() == 1.3);
    REQUIRE(c.get_imaginary() == - 0.1);
    Complex d(8,6);
    Complex e(6,-2);
    c = d / e;
    REQUIRE(c.get_real() == 0.9);
    REQUIRE(c.get_imaginary() == 1.3);
}


TEST_CASE( "test complex class tostring methos" ) {
    Complex a(3.0,5.0);
    std::string temp = a.toString();
    REQUIRE(temp == "3+5i");
}

TEST_CASE( "test complex class magnitude" ) {
    Complex a(3.0,4.0);
    REQUIRE(a.get_magnitude() == 5.0);
}
