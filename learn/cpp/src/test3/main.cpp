#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

class Person {
public:
    Person() {}
    Person(int age1, char *name1) {
        age = age1;
        name = new char[strlen(name1) + 1];
        strcpy(name, name1);
    }
    ~Person() { delete[] name; }

public:
    Person &operator=(Person &p) {
        this->age = p.age;
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
        return *this;
    }

    int operator()(int a, int b) { return a + b; }

public:
    int age;
    char *name;
};

void test01() { cout << Person()(3, 4) << endl; }

int main() {
    test01();
    return 0;
}
