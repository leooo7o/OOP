#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString45");
    string s;
    pt >> s;
    int n=0,min=10000000;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] != ' ')
            n++;
        else {
            if(n!=0)
            min = fmin(min, n);
            n = 0;
        }
    }
    pt << min;
}
