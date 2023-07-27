#ifndef __COMPLEX__
#define __COMPLEX__

// 守卫式声明

class Complex
{

public:
    Complex(){};
    Complex(double r = 0, double i = 0) : re(r), im(i) {}
    ~Complex();
    inline double getReal() const { return re; }
    inline double getImag() const { return im; }

private:
    // 两个私有变量数据
    double re, im;
};

// Complex::Complex(/* args */)
// {
// }

Complex::~Complex()
{
}

#endif