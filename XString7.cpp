#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString7");
    string s;
    pt >> s;
    int len = s.length();
    int a1 = s[0];
    int a2 = s[len-1];
    pt << a1 << a2;
}
