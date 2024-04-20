#include "pt4.h"
using namespace std;
typedef ptin_iterator<double> ptin;
typedef ptout_iterator<double> ptout;
void Solve()
{
    Task("STL1Iter4");
    copy(ptin(0), ptin(), ptout());
}
