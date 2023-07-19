#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    complex c(1, 2);
    cout << c.getReal() << ", " << c.getImag() << endl;
    return 0;
}