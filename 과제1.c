
#include <stdio.h>

int main() {
    int x = -1;

    if (x + 1 == 0) {
        printf("2\n");
    }
    else {
        printf("1\n");
    }

    return 0;
}

// 1의 보수와 2의 보수에서는 수를 저장하는 수가 다른데 x + 1 의 식이 0이 되면 2의 보수 그렇지 않으면 1의 보수를 사용하는 코드 
