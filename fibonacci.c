#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

long long fibo_recursive(int n) {
    if (n <= 2) {
        return 1;
    }
    return fibo_recursive(n - 1) + fibo_recursive(n - 2);
}

long long fibo_iterative(int n) {
    if (n <= 2) {
        return 1;
    }

    long long prev = 1; // F(n-2)
    long long curr = 1; // F(n-1)
    long long next = 0;

    for (int i = 3; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    int n;
    clock_t start, end;
    double duration;

    printf("수열  값: ");
    scanf("%d", &n);

    printf("\n--- 결과 ---\n");

    start = clock();
    long long res1 = fibo_iterative(n);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("순환: F(%d) = %lld (시간: %f 초)\n", n, res1, duration);

    printf("재귀 방식\n");
    start = clock();
    long long res2 = fibo_recursive(n);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("재귀: F(%d) = %lld (시간: %f 초)\n", n, res2, duration);
    return 0;
}
