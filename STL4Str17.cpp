#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <string>

void Solve()
{
    Task("STL4Str17");
    string s;
    pt >> s;
    auto len=unique(s.begin(), s.end(), [](char a, char b) {return (a <= '9' && a >= '0' && b >= '0' && b <= '9') || (b <= 'z' && b >= 'A' && a >= 'A' && a <= 'z'); });
    *len = 0;
    Show(s);
    pt << s ;
}
