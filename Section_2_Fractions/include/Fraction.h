#pragma once
#include <string>

class Fraction {
    int num;
    int denom;
    public:

    Fraction(int a, int b);
    Fraction reciprocal();
    Fraction multiply(int a);
    double toDouble();
    std::string toString();
};