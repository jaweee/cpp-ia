#include <iostream>
#include <string>

using namespace std;

string rmhyphen(const string &s)
{
    int len = s.length();
    int index = 0;
    char *c = (char *)malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++)
    {
        if (s.at(i) == '-')
            continue;
        c[index++] = s.at(i);
    }
    return string(c);
}

int main()
{
    string s = rmhyphen("19-098");
    cout << s << endl;
    string s1 = rmhyphen("2023-34716-122");
    cout << s1 << endl;
}