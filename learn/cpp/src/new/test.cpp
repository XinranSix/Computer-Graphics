//
// Created by yaojie on 2023/5/12.
//

#include <boost/array.hpp>
#include <iostream>

using namespace std;
int main() {
    boost::array<int, 4> arr = {{1, 2, 3, 4}};
    cout << "hi" << arr[0];
    return 0;
}
