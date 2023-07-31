#ifndef __COMPLEX__
#define __COMPLEX__

// 守卫式声明

class Complex
{

public:
    // 这里有了有参构造函数，就不能有默认的构造函数
    // Complex(){};

    // 构造函数with初始化序列
    Complex(double r = 0, double i = 0) : re(r), im(i) {}
    // 操作符重载
    Complex &operator+(const Complex &o) {}

    inline double getReal() const { return re; }
    inline double getImag() const { return im; }

private:
    // 两个私有变量数据
    double re, im;
};

Complex::Complex()
{
}

Complex::~Complex()
{
}

#endif