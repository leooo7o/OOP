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
    Task("STL3Alg10");
    list<int>   L(ptin(0), ptin());
    vector<int> D(ptin(0), ptin());
    L.reverse();
    vector<int>::iterator i=D.begin();
    for(int x=0;x<D.size()/2;x++)i++;
    vector<int>::iterator it=search(i,D.end(),L.begin(),L.end());
    if(it!=D.end())
    {
    	D.insert(it,L.begin(),L.end());
	}
    //Show(D.begin(), D.end(), "D: ");
    copy(D.begin(), D.end(), ptout());
}
