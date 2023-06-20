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

public:
    int age;
    char *name;
};

void test01() {
    Person p1{10, "bob"};
    Person p2;
    p2 = p1;
    cout << p2.age << ' ' << p2.name << endl;
}

int main() {
    test01();
    return 0;
}
