#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int size;
} List;

void insert(List* L, int pos, int item) {
    if (L->size >= MAX || pos < 0 || pos > L->size || item <= 0) return;
    for (int i = L->size; i > pos; i--) L->arr[i] = L->arr[i - 1];
    L->arr[pos] = item;
    L->size++;
}

void delete(List* L, int pos) {
    if (L->size == 0 || pos < 0 || pos >= L->size) return;
    for (int i = pos; i < L->size - 1; i++) L->arr[i] = L->arr[i + 1];
    L->size--;
}

void replace(List* L, int pos, int item) {
    if (pos >= 0 && pos < L->size && item > 0) L->arr[pos] = item;
}

void print(List* L) {
    for (int i = 0; i < L->size; i++) printf("%d ", L->arr[i]);
    printf("\n");
}

int main() {
    List L = { .size = 0 };
    int menu, pos, item;

    while (1) {
        printf("1.ins 2.del 3.rep 4.pri 5.clr 0.exit: ");
        scanf("%d", &menu);
        if (menu == 0) break;

        if (menu == 1 || menu == 3) scanf("%d %d", &pos, &item);
        else if (menu == 2) scanf("%d", &pos);

        if (menu == 1) insert(&L, pos, item);
        else if (menu == 2) delete(&L, pos);
        else if (menu == 3) replace(&L, pos, item);
        else if (menu == 4) print(&L);
        else if (menu == 5) L.size = 0;
    }
    return 0;
}
