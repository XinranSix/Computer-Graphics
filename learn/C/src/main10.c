#include <stdio.h>
#include <stdlib.h>

void fun() { char *p = (char *)malloc(100); }

int main() {
    // 每调用一次fun泄露100个字节
    fun();
    fun();
    return 0;
}