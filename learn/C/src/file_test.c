#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("./file.txt", "r");
    if (fp == NULL) {
        printf("Fail to fopen\n");
        return -1;
    }
    int num;
    char buf[128];
    num = fread(buf, 5, 4, fp);
    printf("buf = %s\n", buf);
    printf("num = %d\n", num);
    return 0;
}
