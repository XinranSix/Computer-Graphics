#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *p;
    p = (char *)malloc(100);
    p = (char *)realloc(p, 50);
    
    return 0;
}