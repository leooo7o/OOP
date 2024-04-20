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
bool  bools(int x1, int x2) {
    if ((abs(x1) %2==0&&abs(x2)%2==0)|| (abs(x1) % 2 == 1 && abs(x2) % 2 == 1)){
        return 1;
    }
    else {
        return 0;
    }
}
void Solve()
{
    Task("STL3Alg32");
    vector<int> V(ptin(0), ptin());
    vector<int>::iterator it=unique(V.begin(),V.end(), bools);
    Show(V.begin(), V.end(), "V: ");
    V.erase(it, V.end());
    Show(V.begin(), V.end(), "V: ");
    copy(V.begin(), V.end(), ptout());
}
