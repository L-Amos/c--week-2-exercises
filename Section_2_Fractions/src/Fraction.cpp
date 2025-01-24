#include "Fraction.h"
#include <numeric>

Fraction::Fraction(int a, int b) {
    int gcd = 1;
    if (a!=0 && b!=0) {
        gcd = std::gcd(a, b);
    }
    num = a/gcd;
    denom = b/gcd;
}

Fraction Fraction::reciprocal() {
    return Fraction(Fraction::num, Fraction::denom);
}
Fraction Fraction::multiply(int a) {
    return Fraction(num * a, denom);
}
double Fraction::toDouble() {
    return double(float(num) / float(denom));
}

std::string Fraction::toString() {
    if (num==0) {
        return "0";
    }
    return std::to_string(num) + "/" + std::to_string(denom);
}

