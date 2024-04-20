#include "pt4.h"
using namespace std;

#include <iterator>
#include <vector>
#include <deque>
#include <list>

typedef ptin_iterator<int> ptin;
typedef ptout_iterator<int> ptout;

void Solve()
{
    Task("STL2Seq20");
    deque<int> D(ptin(0), ptin());
    D.erase(D.begin()+D.size() / 2, D.begin()+D.size()/2 +1);
    copy(D.begin(), D.end(), ptout());
}
