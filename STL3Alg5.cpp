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
bool no(int x)
{
	return (x<0);
}
bool yes(int x)
{
	return (x>0);
}
void Solve()
{
    Task("STL3Alg5");
    list<int> L(ptin(0), ptin());
    list<int>::iterator it1=find_if(L.begin(),L.end(),no);
    it1++; 
       L.insert(it1,0);
    list<int>::iterator it2=L.begin();
    while(find_if(it2,L.end(),yes)!=L.end()){
    	it2=find_if(it2,L.end(),yes);
    	it2++;
	}
	it2--;
//    list<int>::iterator it2=find_if(L.end(),L.begin(),yes);
//    it2++;
    L.insert(it2,0);
   // Show(L.begin(), L.end(), "L: ");
    copy(L.begin(), L.end(), ptout());
}
