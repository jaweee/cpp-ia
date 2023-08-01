#ifndef __Singleton__
#define __Singleton__

class Singleton
{
public:
    static Singleton &getInstance() { return s; };
    ~Singleton();

private:
    Singleton();
    Singleton(const Singleton &rhs);
    static Singleton s;
};

#endif