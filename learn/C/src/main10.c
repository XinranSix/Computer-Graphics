#include <stdio.h>

int main(int argc, char *argv[]) {

    int a = 100;
    int *p = &a;
    int **q = &p;

    printf("a = %d %d %d\n", a, *p, **q);
    printf("&a = %p %p %p\n", &a, p, *q);
    printf("&p = %p %p\n", &p, q);
    printf("&q = %p\n", &q);

    return 0;
}