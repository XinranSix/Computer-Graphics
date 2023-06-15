#include <stdio.h>

int main(int argc, char *argv[]) {
    char *a;
    short *b;
    int *c;
    long *d;
    float *e;
    double *f;

    printf("sizeof(a) = %lld\n", sizeof(a));
    printf("sizeof(b) = %lld\n", sizeof(b));
    printf("sizeof(c) = %lld\n", sizeof(c));
    printf("sizeof(d) = %lld\n", sizeof(d));
    printf("sizeof(e) = %lld\n", sizeof(e));
    printf("sizeof(f) = %lld\n", sizeof(f));

    return 0;
}