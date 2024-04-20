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
    Task("STL3Alg47");
    vector<int> V(ptin(0), ptin());
    sort(V.begin() + V.size()/2, V.end());
    Show(V.begin(), V.end(), "V: ");
    copy(V.begin(), V.end(), ptout());
    inplace_merge(V.begin(), V.begin() + V.size() / 2, V.end());
    Show(V.begin(), V.end(), "V: ");
    copy(V.begin(), V.end(), ptout());
}
