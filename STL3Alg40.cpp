#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <functional>
typedef ptin_iterator<int> ptin;
typedef ptout_iterator<int> ptout;

void Solve()
{
    Task("STL3Alg40");
    list<int> L(ptin(0), ptin());
    list<int>::iterator it;
    int x1=0, x2=0;
    for (it = L.begin(); it != L.end(); it++) {
        if (abs(*it) % 2 == 0)
            x1++;
        else x2++;
    }
    Show(x1);
    Show(x2);
    pt << x1 << x2;
    Show(L.begin(), L.end(), "L: ");
    //copy(L.begin(), L.end(), ptout());
}
