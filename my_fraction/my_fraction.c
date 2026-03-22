#include "my_fraction.h"
#include <stdlib.h>

int get_gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

Fraction simplify(Fraction f) {
    int common = get_gcd(f.num, f.den);
    f.num /= common;
    f.den /= common;
    if (f.den < 0) {
        f.num = -f.num;
        f.den = -f.den;
    }
    return f;
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction r;
    r.num = (f1.num * f2.den) + (f2.num * f1.den);
    r.den = f1.den * f2.den;
    return simplify(r);
}

Fraction subtract(Fraction f1, Fraction f2) {
    Fraction r;
    r.num = (f1.num * f2.den) - (f2.num * f1.den);
    r.den = f1.den * f2.den;
    return simplify(r);
}

Fraction multiply(Fraction f1, Fraction f2) {
    Fraction r;
    r.num = f1.num * f2.num;
    r.den = f1.den * f2.den;
    return simplify(r);
}

Fraction divide(Fraction f1, Fraction f2) {
    Fraction r;
    r.num = f1.num * f2.den;
    r.den = f1.den * f2.num;
    return simplify(r);
}
