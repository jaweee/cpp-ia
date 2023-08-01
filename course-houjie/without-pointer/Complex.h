#ifndef __COMPLEX__
#define __COMPLEX__

// 守卫式声明

#include <iostream>
using namespace std;

class Complex
{

public:
    // 这里有了有参构造函数，就不能有默认的构造函数
    // Complex(){};

    // 构造函数with初始化序列
    inline Complex(double r = 0, double i = 0) : re(r), im(i) {}
    // 操作符重载
    Complex &operator+=(const Complex &c);
    inline void testThispointer();
    // 获取私有数据
    inline double getReal() const { return re; }
    inline double getImag() const { return im; }

private:
    // 两个私有变量数据
    double re, im;

    friend Complex &_doapl(Complex *ths, const Complex &c);
};

// 返回引用是因为让 +=可以连写，a+=b+=c
// 隐藏的this指针
inline Complex &Complex::operator+=(const Complex &c)
{
    return _doapl(this, c);
}

// +=的动作交给了下面这个函数
Complex &_doapl(Complex *ths, const Complex &c)
{
    ths->re += c.re;
    ths->im += c.im;
    return *ths;
}

// 所有的成员函数都是有一个this指针被隐藏了
void Complex::testThispointer()
{
    cout << "this: " << this->getImag() << endl;
}

// 非成员函数，让两个复数相加
inline Complex operator+(const Complex &x, const Complex &y)
{
    return Complex(x.getReal() + y.getReal(), x.getImag() + y.getImag());
}

// 非成员函数，让复数加实数
inline Complex operator+(const Complex &x, double y)
{
    return Complex(x.getReal() + y, x.getImag());
}

// 非成员函数，让实数加复数
inline Complex operator+(const double x, const Complex &y)
{
    return Complex(x + y.getReal(), y.getImag());
}

// 非成员函数
// 由于要连串使用，所以要返回一个ostream，由于返回的不是本地local，所以可以是引用
inline ostream &operator<<(ostream &ost, const Complex &c)
{
    return ost << '(' << c.getReal() << ", " << c.getImag() << ")" << endl;
}
#endif