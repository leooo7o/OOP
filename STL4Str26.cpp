#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <string>

void Solve()
{
    Task("STL4Str26");
    string s;
    pt >> s;
    s.erase(remove_if(s.begin(), s.end(), [](int c) {return c >= '0' && c <= '9'; }), s.end());
    Show(s);
    pt << s;
}
