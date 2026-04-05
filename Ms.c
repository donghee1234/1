#include <stdio.h>

#define N 3

int main() {
    int arr[N][N] = { 0 };
    int r = 0, c = N / 2;
    int nr, nc;

    for (int i = 1; i <= N * N; i++) {
        arr[r][c] = i;
        nr = (r - 1 < 0) ? N - 1 : r - 1;
        nc = (c + 1 >= N) ? 0 : c + 1;

        if (arr[nr][nc] != 0) r++;
        else {
            r = nr;
            c = nc;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%3d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");

    int s1, s2, d1 = 0, d2 = 0;
    for (int i = 0; i < N; i++) {
        s1 = s2 = 0;
        for (int j = 0; j < N; j++) {
            s1 += arr[i][j];
            s2 += arr[j][i];
        }
        printf("가로%d합: %d, 세로%d합: %d\n", i + 1, s1, i + 1, s2);
        d1 += arr[i][i];
        d2 += arr[i][N - 1 - i];
    }
    printf("대각선1합: %d, 대각선2합: %d\n", d1, d2);

    return 0;
}
