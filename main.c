#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_math.h"

int main() {
    int a, b;

    if (scanf("%d %d", &a, &b) != 2) return 0;

    printf("GCD: %d, LCM: %d\n", gcd(a, b), lcm(a, b));

    return 0;
}
