#include <stdio.h>

void myfun() {

    int a;
    static int num;
    printf("a = %d\n", a);
    printf("num = %d\n", num);
}

void myfun1() {

    static int num1 = 100;
    num1++;
    printf("num1 = %d\n", num1);
}

int main(int argc, char *argv[]) {

    myfun();
    myfun1();
    myfun1();
    myfun1();

    return 0;
}