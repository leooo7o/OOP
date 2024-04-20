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
    Task("STL2Seq26");
    list<int>  L1(ptin(0), ptin());
    list<int>  L2(ptin(0), ptin());
    int size1=L2.size()/2;
    int size2=L1.size()/2;
    list<int>::iterator i1 = L2.begin();
    for (int i = 0; i < L2.size() / 2; i++)
    {
        i1++;
    }
    list<int>::iterator i2 = L2.end();
    L1.splice(L1.begin(), L2, i1, i2);
    list<int>::iterator i3 = L1.begin();
    for (int i = 0; i <size1; i++)
    {
        i3++;
    }
    list<int>::iterator i4 = L1.end();
    for (int i = 0; i <= (size1+size2); i++)
    {
        i4++;
    }
    L2.splice(L2.end(), L1,i3, i4);
    //Show(L1.begin(), L1.end(), "L1: ");
    //Show(L2.begin(), L2.end(), "L2: ");
    copy(L1.begin(), L1.end(), ptout());
    copy(L2.begin(), L2.end(), ptout());
}
