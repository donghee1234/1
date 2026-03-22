#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_fraction.h"

int main() {
    int n1, d1, n2, d2;
    char op;

    if (scanf("%d/%d %c %d/%d", &n1, &d1, &op, &n2, &d2) != 5) return 0;

    Fraction f1 = { n1, d1 };
    Fraction f2 = { n2, d2 };
    Fraction res;

    if (op == '+') res = add(f1, f2);
    else if (op == '-') res = subtract(f1, f2);
    else if (op == '*') res = multiply(f1, f2);
    else if (op == '/') res = divide(f1, f2);

    if (res.den == 1) {
        printf("%d\n", res.num);
    }
    else {
        printf("%d/%d\n", res.num, res.den);
    }

    return 0;
}
