#include <iostream>
#include <chrono>

using namespace std;

int main() {
    auto start = std::chrono::system_clock::now();
    std::time_t tt;
    tt = std::chrono::system_clock::to_time_t(start);
    string t = ctime(&tt);
    cout << "today is" << t << endl;
}
