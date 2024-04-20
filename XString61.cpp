#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString61");
    string s;
    pt >> s;
    int len = s.length();
    int p1=0,p2=0;
    for (int i = len; i >= 0; i--)
    {
        if (s[i] == '\\') {
            p1 = i;
            break;
        }
    }
    s.erase(p1+1, len);
    for (int i = 0; i <p1; i++)
    {
        if (s[i] == '\\')
            p2 = i;
    }
    if (p2 == 0)
    {
        s="\\";
    }
    else {
        s.erase(0, p2 + 1);
        len = s.length();
        s[len - 1] = 0;
    }
    pt << s;
}
