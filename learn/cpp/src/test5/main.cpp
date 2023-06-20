/**
 * @file    :   main.cpp
 * @date    :   2023/06/20 17:50:53
 * @author  :   yaojie
 * @version :   1.0
 * 模板测试
 */

#include <iostream>

using namespace std;

template<typename T>
void arr_sort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (min > arr[j]) {
                idx = j;
            }
        }
        if (i != idx) {
            T t = arr[idx];
            arr[idx] = arr[i];
            arr[i] = t;
        }
    }
}

void test01() {}

int main() { return 0; }
