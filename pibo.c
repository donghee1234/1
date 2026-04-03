#include <stdio.h>
#include <time.h>

long long pibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return pibo(n - 1) + pibo(n - 2);
}

int gcd_steps(long long a, long long b) {
    int count = 0;
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
        count++;
    }
    return count;
}

int main() {
    int n;

    printf("n | Fibonacci | GCD Steps | Time (sec)\n");
    printf("---------------------------------------\n");

    for (n = 10; n <= 40; n = n + 5) {
        clock_t start = clock();

        long long f1 = pibo(n);
        long long f2 = pibo(n - 1);
        int steps = gcd_steps(f1, f2);

        clock_t end = clock();
        double sec = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d | %lld | %d | %.3f\n", n, f1, steps, sec);
    }

    return 0;
}
