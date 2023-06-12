#include <stdio.h>
int main() {
    int a[3][5]; // 定义了一个 3 行 5 列的一个二维数组
    int(*p)[5]; // 定义一个数组指针变量 p，p+1 跳一个有 5 个元素的整型数组
    printf("a=%p\n", a);       // 第 0 行的行地址
    printf("a+1=%p\n", a + 1); // 第 1 行的行地址，a 和 a +1 差 20 个字节
    p = a;
    printf("p=%p\n", p);
    printf("p+1=%p\n", p + 1); // p+1 跳一个有 5 个整型元素的一维数组
    return 0;
}