#include <stdio.h>

struct packed_data {
    unsigned int a : 2;
    unsigned int b : 6;
    unsigned int c : 4;
    unsigned int d : 4;
    unsigned int i;
} data;

int main() {
    printf("%d\n", sizeof(data));
    printf("%p\n", &data);
    printf("%p\n", &(data.i));
    return 0;
}