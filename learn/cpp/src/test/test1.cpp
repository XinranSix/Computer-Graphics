#include <iostream>

using namespace std;

int main() {
    const int a = 10;
    // a = 100;
    int *p = (int *)&a;
    *p = 100;
    cout << a << endl;
    cout << *p << endl;
    return 0;
}
