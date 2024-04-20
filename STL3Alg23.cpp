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
    Task("STL3Alg23");
    list<int> L1(ptin(0), ptin());
    list<int> L2(ptin(0), ptin());
    list<int>::iterator it=L1.begin();
    for(int i=0;i<L1.size()/4;i++)
    {
    	it++;
	}
    list<int>::reverse_iterator it1=L1.rbegin();
    for(int i=0;i<L1.size()/2;i++)
    {
    	it1++;
	}
	swap_ranges(L1.begin(), it ,it1 );
    list<int>::iterator it2=L2.begin();
    for(int i=0;i<L2.size()/2;i++)
    {
    	it2++; 
	}
    reverse(it2,L2.end());
    Show(L1.begin(), L1.end(), "L1: ");
    Show(L2.begin(), L2.end(), "L2: ");

    copy(L1.begin(), L1.end(), ptout());
    copy(L2.begin(), L2.end(), ptout());
}
