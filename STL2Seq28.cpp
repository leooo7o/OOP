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
    Task("STL2Seq28");
    deque<int> D(ptin(0), ptin());

    Show(D.begin(), D.end(), "D: ");
    //copy(D.begin(), D.end(), ptout());
}
