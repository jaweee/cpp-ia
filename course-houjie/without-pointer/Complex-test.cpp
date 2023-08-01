#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    Complex c(1, 2);
    cout << "c: \t" << c << endl;
    Complex c1;
    cout << "c1: \t" << c1 << endl;
    Complex c2(3, 4);
    cout << "c2: \t" << c2 << endl;
    c1+=c+=c2;
    cout << "c1+=c+=c2: \t" << c1 << endl;
    Complex c3 = c1+c2;
    cout << "c3=c1+c2: \t" << c3 << endl;
    return 0;
}