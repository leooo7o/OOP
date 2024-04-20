#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <string>
void Solve()
{
    Task("STL4Str8");
    string s;
    pt >> s;
    string::iterator it = s.begin();
    it++;
    it++;
    int x = 2;
    int i = 0;
    if (it == s.end()) { 
    s.insert(s.end(), 3, '*'); 
    pt << s; 
    }
    else {
        while (it != s.end())
        {
            s.insert(it, 3, '*');
            x += 5;
            it = s.begin();
            for (i = 0; i < x; i++) {
                if (it == s.end())break;
                it++;
            }
        }
        if (x == i) { s.insert(s.end(), 3, '*'); }
        s.insert(s.end(), '\0');
        Show(s);
        pt << s;
    }
}
