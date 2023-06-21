#include <iostream>
#include "vec2.h"

using namespace std;

void test01() {
    Vec2 v1{1, 2};
    cout << v1 << endl;
}

void test02() {
    Vec2 v1 = {1, 2};
    cout << v1 << endl;
}

int main() {
    test01();
    test02();
    return 0;
}
