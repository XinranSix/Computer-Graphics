#include <iostream>

using namespace std;

class Animal {
public:
    int age;
};

class Sheep : virtual public Animal {
public:
    int id;
};

class Camel : virtual public Animal {
public:
    int camel_num;
};

class SheepCamel : public Sheep, public Camel {};

void test01() {
    SheepCamel p;
    p.age = 10;
}

int main() {
    test01();
    return 0;
}
