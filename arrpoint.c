#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;
    int *arr;
    int sum = 0, max, min;

    printf("배열 크기: ");
    scanf("%d", &N);

    arr = (int *)malloc(sizeof(int) * N);

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        *(arr + i) = rand() % (N + 1);
    }

    printf("처음: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    printf("끝: ");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    max = min = *arr;
    for (int i = 0; i < N; i++) {
        int current = *(arr + i);
        sum += current;
        
        if (current > max) max = current;
        if (current < min) min = current;
    }

    printf("총합: %d / 최대값: %d / 최소값: %d\n", sum, max, min);

    free(arr);

    return 0;
}
