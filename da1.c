#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    float coef;
    int expon;
} Term;

typedef struct {
    Term terms[100];
    int count;
} Polynomial;

void addTerm(Polynomial* p, float coef, int expon) {
    if (coef == 0) return;
    p->terms[p->count].coef = coef;
    p->terms[p->count].expon = expon;
    p->count++;
}

Polynomial add(Polynomial A, Polynomial B) {
    Polynomial C;
    C.count = 0;
    int a = 0, b = 0;

    while (a < A.count && b < B.count) {
        if (A.terms[a].expon > B.terms[b].expon) {
            C.terms[C.count++] = A.terms[a++];
        }
        else if (A.terms[a].expon < B.terms[b].expon) {
            C.terms[C.count++] = B.terms[b++];
        }
        else {
            float sum = A.terms[a].coef + B.terms[b].coef;
            if (sum != 0) {
                C.terms[C.count].coef = sum;
                C.terms[C.count].expon = A.terms[a].expon;
                C.count++;
            }
            a++;
            b++;
        }
    }

    for (; a < A.count; a++) {
        C.terms[C.count++] = A.terms[a];
    }
    for (; b < B.count; b++) {
        C.terms[C.count++] = B.terms[b];
    }

    return C;
}

void printPoly(Polynomial p) {
    for (int i = 0; i < p.count; i++) {
        printf("%.0fX^%d", p.terms[i].coef, p.terms[i].expon);
        if (i < p.count - 1 && p.terms[i + 1].coef > 0) printf("+");
    }
    printf("\n");
}

int main() {
    Polynomial A = { .count = 0 }, B = { .count = 0 }, C;
    int n, e;
    float c;

    printf("식 A 항 개수: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%f %d", &c, &e);
        addTerm(&A, c, e);
    }

    printf("식 B 항 개수: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%f %d", &c, &e);
        addTerm(&B, c, e);
    }

    C = add(A, B);
    printf("덧셈 결과: ");
    printPoly(C);

    return 0;
}
