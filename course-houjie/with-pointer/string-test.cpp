#include <iostream>
#include "string.h"

using namespace std;

int main(){
    // String s = String();
    // String s = String("hello");
    String s("hello");
    cout << s.get_c_char() << endl;
    String s1;
    cout << s1.get_c_char() << endl;
    String s2(s);
    cout << s2.get_c_char() << endl;
    String s3 = s2;
    cout << s3.get_c_char() << endl;
    return 0;
}