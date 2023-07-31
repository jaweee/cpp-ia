#ifndef __STRING__
#define __STRING__

#include <cstring>

using namespace std;

class String
{
public:
    // 构造函数
    String(const char *m = 0);
    // 拷贝构造函数
    String(const String &str);
    // 拷贝复制函数
    String &operator=(const String &str);
    // 析构函数
    ~String();
    // 其他函数
    inline char *get_c_char() const { return m_data; }

private:
    char *m_data;
};
// inline String::String(const char *m = 0)，如果这样子写，编译器会报错，说重复定义
inline String::String(const char *m)
{
    // 创建一个等大小空间的
    if (m)
    {
        m_data = new char[strlen(m) + 1];
        strcpy(m_data, m);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline String::~String()
{
    delete[] m_data;
}

/* 拷贝构造函数 */

inline String::String(const String &str)
{
    //
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

/* 拷贝赋值函数*/
inline String &String::operator=(const String &str)
{
    // 防止自己赋值自己
    if (this == &str)
    {
        // 如果自己和自己相同，则把自己传出去
        return *this;
    }
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

#endif