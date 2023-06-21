#include <iostream>
#include <vector>

using namespace std;

void test01() {

    vector<int> v{1, 2, 3, 4, 5};
    v.push_back(6);

    for (int &it : v) {
        cout << it << ' ';
    }
}

int main() {
    test01();
    return 0;
}