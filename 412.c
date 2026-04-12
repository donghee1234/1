#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
    char name;
    int id;
    int score;
};

int main() {
    int N;
    int sum = 0;

    printf("학생 수는 몇 명인가요? : ");
    scanf("%d", &N);

    struct Student *arr = (struct Student *)malloc(sizeof(struct Student) * N);

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        sprintf(arr[i].name, "Caroline Simmons"); 
        arr[i].id = i + 1;
        arr[i].score = rand() % 100 + 1;
        sum += arr[i].score;
    }

    int max_idx = 0;
    int min_idx = 0;

    for (int i = 1; i < N; i++) {
        if (arr[i].score > arr[max_idx].score) {
            max_idx = i;
        }
        if (arr[i].score < arr[min_idx].score) {
            min_idx = i;
        }
    }

    printf("\n--- 결과 발표 ---\n");
    printf("최고점 학생: %s (학번: %d, 점수: %d)\n", arr[max_idx].name, arr[max_idx].id, arr[max_idx].score);
    printf("최저점 학생: %s (학번: %d, 점수: %d)\n", arr[min_idx].name, arr[min_idx].id, arr[min_idx].score);
    printf("전체 평균: %.2f점\n", (float)sum / N);

    free(arr);

    return 0;
}
