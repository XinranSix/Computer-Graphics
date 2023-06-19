#include <iostream>
#include <memory>

using namespace std;

class Person {
    Person(){};
};

int main() {
    unique_ptr<Person> p;
    return 0;
}
