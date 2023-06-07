#include <iostream>

using namespace std;

// 设置递归终点, 当参数包解包完全, 适配空包
void ShowList() { cout << endl; }
// 递归形式调用解包, 每一次解出一个参数
template <class T, class... Args> void ShowList(T &val, Args... args) {
    cout << val << endl;
    ShowList(args...);
}
int main() {
    ShowList("dsadsa", 2, 5, 6, "edsad");
    return 0;
}