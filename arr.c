#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    int arr[N];
    int sum = 0, max, min;

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % (N + 1);
    }

    printf("처음: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("끝: ");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    max = min = arr;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    printf("총합: %d / 최대값: %d / 최소값: %d\n", sum, max, min);

    return 0;
}
