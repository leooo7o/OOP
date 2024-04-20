#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString7");
    string s;
    pt >> s;
    string::size_type len = s.length();
    char x1 = s[0];
    char x2 = s[len-1];
    pt << (int)x1;
    pt << (int)x2;
}
