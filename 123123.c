#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r, c, v;
} Element;

typedef struct {
    Element* data;
    int size;
} ArrayList;

typedef struct {
    int rows, cols;
    ArrayList* L; 
} SparseMatrix;

int main() {
    SparseMatrix* m = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    m->rows = 10; 
    m->cols = 10;
    
    m->L = (ArrayList*)malloc(sizeof(ArrayList));
    m->L->data = (Element*)malloc(sizeof(Element) * 20);
    m->L->size = 0;

    for (int i = 0; i < 20; i++) {
        m->L->data[i].r = i / 2;
        m->L->data[i].c = (i * 7) % 10;
        m->L->data[i].v = i + 1;
        m->L->size++;
    }

    ArrayList* result = (ArrayList*)malloc(sizeof(ArrayList));
    result->data = (Element*)malloc(sizeof(Element) * 20);
    result->size = 0;
    int move_count = 0;

    for (int col = 0; col < m->cols; col++) {
        for (int i = 0; i < m->L->size; i++) {
            if (m->L->data[i].c == col) {
                result->data[result->size].r = m->L->data[i].c;
                result->data[result->size].c = m->L->data[i].r;
                result->data[result->size].v = m->L->data[i].v;
                result->size++;
                move_count++;
            }
        }
    }

    printf("데이터 이동 횟수: %d\n", move_count);
    for (int i = 0; i < result->size; i++) {
        printf("%d행 %d열: %d\n", result->data[i].r, result->data[i].c, result->data[i].v);
    }

    free(result->data);
    free(result);
    free(m->L->data);
    free(m->L);
    free(m);

    return 0;
}
