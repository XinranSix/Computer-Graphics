#include <stdio.h>

void fun(int (*p)[5], int x, int y) { p[0][1] = 101; }

int main() {
    int a[3][5] = {0};
    fun(a, 3, 5);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}