#include <iostream>

using namespace std;
istream& f(istream& i);

int main() {
    f(cin);
    cout << "current iostate: " <<cin.rdstate() << "， failbit: " << cin.failbit << ", eofbit: " << endl;
    return 0;
}

istream& f(istream& i) {
    string w = "";
    while (i >> w)
    {
        cout << w << endl;
    }
    
    // 1. clear()是
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.eofbit);
    return i;
}