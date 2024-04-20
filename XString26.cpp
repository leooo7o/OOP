#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString26");
    int n;
    string s;
    pt >> n;
    pt >> s;
    int len = s.length();
    if (len >= n)
    {
        s.erase(0, len - n);
    }
    else
    {
        s.insert(0, n-len, '.');
    }
    pt << s;
}
