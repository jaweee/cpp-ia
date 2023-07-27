#ifndef __STRING__
#define __STRING__

class String
{
public:
    // 构造函数
    String(const char *m = 0);
    // 拷贝构造函数
    String(const String &ot);
    // 拷贝复制函数
    ~String();

private:
    char *m_data;
};

String::String(const char *m = 0)
{
}

String::~String()
{
}

#endif