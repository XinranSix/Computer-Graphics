#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

void test01() {
    int i = negate<int>()(-1);
    cout << i << endl;
}

void test02() {}

int main() {
    test01();
    return 0;
}
