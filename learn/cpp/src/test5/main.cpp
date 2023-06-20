#include <iostream>
#include <string>

using namespace std;

class Calc {
public:
    int calc(int a, int b, string cmd) {
        if (cmd == "+") {
            return a + b;
        }
        return 0;
    }
};

void test01() {}

int main() {
    test01();
    return 0;
}
