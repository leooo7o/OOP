#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString39");
    string s,a;
    pt >> s;
    int len = s.length();
    int p1 = 0,p2 = 0;
    int i = 0;
    for (; i < len; i++)
    {
        if (s[i] == ' ') {
            p1 = i;
            i++;
            break;
        }
    }
    for (; i < len; i++)
    {
        if (s[i] == ' ') {
            p2 = i;
            break;
        }
    }
    if (p2 == 0) {
        s.empty();
        s[0] = 0;
        pt << s;
    }
    else if(p1!=0&&p2!=0)
    {
        a=s.substr(p1+1, p2-p1-1);
        pt << a;
    }
}
