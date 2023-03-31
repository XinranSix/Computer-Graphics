#include <iostream>

class Complex {
private:
    double re; // 复数的实部
    double im; // 复数的虚部

public:
    Complex(double re = 0.0, double im = 0.0);
    Complex(const Complex&);// 拷贝构造函数
    ~Complex(); // 析构函数

// getter 和 setter
public:
    double getRe();
    void setRe(double re);
    double getIm();
    void setIm(double im);

// 运算符重载
public:
    /*
        输出输入算子重载
        输出输入算子重载推荐使用友元
    */
    friend std::istream &operator>>(std::istream&, Complex&);
    friend std::ostream &operator<<(std::ostream&, const Complex&);

    /*
        一元运算符重载：++、--、-，！
    */

    /*
        二元运算符重载：+、-、*、/
    */
};

int main() {
    // Complex c;
    // std::cin >> c;
    // std::cout << c << std::endl;
    system("pause");
    return 0;
}