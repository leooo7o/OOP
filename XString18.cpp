#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString18");
    string s;
    pt >> s;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    }
    pt << s;
}
