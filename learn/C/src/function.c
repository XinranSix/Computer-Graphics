#include <stdio.h>

void fun() {
    static int num = 3;
    num++;
    printf("num = %d\n", num);
}
int main() {
    fun();
    fun();
    fun();
}