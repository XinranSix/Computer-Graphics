#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2> &p) {
    cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}

template<class T1, class T2>
class Person {
    friend void printPerson(Person<T1, T2> &p) {
        cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
    }

    friend void printPerson2<>(Person<T1, T2> &p);

public:
    Person(T1 name, T2 age) {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

// 1、全局函数在类内实现
void test01() {
    Person<string, int> p("Tom", 20);
    printPerson(p);
}

// 2、全局函数在类外实现
void test02() {
    Person<string, int> p("Jerry", 30);
    printPerson2(p);
}

int main() {

    // test01();
    test02();

    return 0;
}