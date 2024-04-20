#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString63");
    string s;
    int k;
    pt >> s;
    pt >> k;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = (s[i] - 'a' + k) % 26 + 'a';
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (s[i] - 'A' + k) % 26 + 'A';
    }
    pt << s;
}
