#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int polyA[21] = { 0 }; 
    int polyB[21] = { 0 }; 
    int result[41] = { 0 };
    int i, j, coef, exp;

    printf("식 A 입력 (계수 지수 입력, 끝내려면 -1 -1):\n");
    while (1) {
        scanf("%d %d", &coef, &exp);
        if (exp == -1) break;
        polyA[exp] = coef;
    }

    printf("식 B 입력 (계수 지수 입력, 끝내려면 -1 -1):\n");
    while (1) {
        scanf("%d %d", &coef, &exp);
        if (exp == -1) break;
        polyB[exp] = coef;
    }

    for (i = 0; i <= 20; i++) {
        for (j = 0; j <= 20; j++) {
            if (polyA[i] != 0 && polyB[j] != 0) {
                result[i + j] += polyA[i] * polyB[j];
            }
        }
    }

    printf("\n결과: ");
    for (i = 40; i >= 0; i--) {
        if (result[i] != 0) {
            printf("%dX^%d", result[i], i);
            if (i > 0) printf("+");
        }
    }
    printf("\n");

    return 0;
}
