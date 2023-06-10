#include <iostream>

using namespace std;

void ShowList() { cout << endl; }

template <class T, class... Args> void ShowList(T &val, Args... args) 
{
    cout << val << endl;
    ShowList(args...);
}

int main() {
    ShowList("dsadsa", 2, 5, 6, "edsad");
    while (true) {
    }

    return 0;
}

class Perosn { 
private:
    int ages;
};