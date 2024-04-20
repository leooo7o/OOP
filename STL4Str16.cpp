#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <string>

void Solve()
{
    Task("STL4Str16");
    string s;
    pt >> s;
    auto i = s.begin();
    advance(i, s.size() / 2);
    auto it = s.begin();
    advance(it, s.size() / 2);
    auto itr=s.begin();
    while((itr= find_first_of(i, s.end(), s.begin(), it))!=s.end()){
        s.erase(itr);
        i=itr;
    }
    s[s.length()] = 0;
    pt << s;
}