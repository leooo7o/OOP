#include "pt4.h"
#include<algorithm>
using namespace std;
typedef ptin_iterator<double> ptin;
typedef ptout_iterator<double> ptout;
int n = 1;
bool bools(int x)
{
    n++;
    return n % 2 == 0;
}
void Solve()
{
    Task("STL1Iter10");
    remove_copy_if(ptin(0), ptin(), ptout(), bools);
}
