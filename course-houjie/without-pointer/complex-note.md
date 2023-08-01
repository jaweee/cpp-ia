# Complex

设计 Complex 类，**不带指针**

### 1. 头文件与类的声明

```cpp
#ifndef __DefendDeclaration__
#define __DefendDeclaration__

class Complex{

public:

private:

}

#endif
```

这就是守卫式声明，如果不存在 DefendDeclaration 才进入 define，否则不再重复进入

### 2. 构造函数

- 类的数据是什么
  - 实部和虚部
  - 类型是 double
- 类的构造函数
  - 参数是实部和虚部
  - 没有返回值
  - 函数名和类名相同
  - 使用初始化序列
- inline
  - 推荐编译器将此函数编译为内联函数

```cpp
class Complex{

public:
   inline Complex(double r = 0, double i = 0): re(r), im(i){}

private:
   double re, im;

}
```

### 3. 参数传递和返回值

- 引用在底层就是一个指针，在传递参数的时候最好是传递引用
- 所有的参数，尽量传引用
- 所有返回值，尽量穿引用

### 4. 操作符重载

### 1）成员函数

```cpp
class Complex {
public:
   ...
   Complex& operator += (const Complex& c);
   ...

private:
   ...

   friend Complex& _doapl(Complex* ths, const Complex& c);
}

// 成员函数的操作符重载
inline Complex& Complex::operator += (const Complex& c) {
   return _doapl(this, c);
}

// 交给了友元函数
// 相同 class 的所有 objects 互为友元
// 传递者无需知道接收者如何定义
Complex& _doapl(Complex* ths, const Complex& c) {
   ths->re += c.re;
   ths->im += c.im;
   return *ths;
}
```

- \_doapl (do assignment plus)
- 类成员函数隐藏了 this 指针

### 2）非成员函数

除了复数加复数，那么就忽略了复数加常数、常数加常数

```cpp
class Complex {
public:
   ...

private:
   ...

// 非成员操作符重载，复数加复数
Complex operator + (const Complex& x, const Complex& y ) {
   return Complex(x.getReal() + y.getReal(), x.getImag() + y.getImag());
}

// 非成员操作符重载，复数加实数
Complex operator + (const Complex& x, double y ) {
   return Complex(x.getReal() + y, x.getImag());
}

// 非成员操作符重载，实数加复数
Complex operator + (double x, const Complex& y ) {
   return Complex(x + y.getReal(), y.getImag());
}

// 非成员操作符重载
ostream& operator << (ostream& ost, const Complex& c) {
   return ost << "(" << c.getReal() << ", " << c.getImag() <<")";
}

}
```

### 总结

1. 数据封装在 private 里
2. 函数参数尽量使用 reference 传递
3. 函数返回值尽量使用 reference 传递
4. 在类的 body 里应该加 const 的就应该加 const
5. 构造函数有一个特殊的语法，

```txt
注3： 在函数的 body 里面创建的空间会被回收掉，所以，这个时候你把 local 中创建的引用给传出去，后面再使用时无内存可被引用

注4：- 不加有可能是 const 成员调用非 const 成员，编译器觉得这是不合理的事情
```
