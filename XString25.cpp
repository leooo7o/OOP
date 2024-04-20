#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString25");
    string s1;
    int num=0;
    pt >> s1;
    int len = s1.length();
    for (int i = 0; i < len; i++)
    {
        num = num * 10 + s1[i]-'0';
    }
    int x = num;
    int n=0;
    while (x)
    {
        x = x / 2;
        n++;
    }
    char*s2=new char[n];
    s2[n] = 0;
    while (num)
    {
        s2[n-1] = num % 2+'0';
        num = num / 2;
        n--;
    }
    pt << s2;
}
