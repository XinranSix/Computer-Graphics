#include <stdio.h>

#define AAA

int main(int argc, char *argv[]) {

#ifdef AAA
    printf("hello kitty!!\n");
#else
    printf("hello 千锋edu\n");
#endif
    return 0;
}