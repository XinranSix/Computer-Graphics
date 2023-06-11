#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 1;
    int sum = 0;
JOOP:
    sum += i;
    i++;
    if (i <= 100) {
        goto JOOP;
    }
    printf("1 + 2 + 3 + ... + 100 = %d\n", sum);
    return 0;
}