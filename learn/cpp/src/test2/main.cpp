#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person() {}
    Person(int age) : age(age) {}
    Person(const Person &p) { this->age = p.age; }

public:
    Person operator++() {
        this->age = this->age + 1;
        return *this;
    }

    Person operator++(int) {
        Person tmp = *this;
        this->age++;
        return tmp;
    }

private:
    int age;

    friend ostream &operator<<(ostream &os, const Person &p);
};

ostream &operator<<(ostream &os, const Person &p) { return os << p.age; }

int main() {
    Person p1{10};
    cout << p1 << endl;
    cout << ++p1 << endl;
    cout << p1 << endl;
    cout << p1++ << endl;
    cout << p1 << endl;

    return 0;
}
