#ifndef __COMPLEX__
#define __COMPLEX__

// 守卫式声明

class complex
{

public:
    complex(){};
    complex(double r = 0, double i = 0) : re(r), im(i) {}
    ~complex();
    inline double getReal() const { return re; }
    inline double getImag() const { return im; }

private:
    // 两个私有变量数据
    double re, im;
};

// complex::complex(/* args */)
// {
// }

complex::~complex()
{
    cout << "这里是析构函数" << endl;
}

#endif