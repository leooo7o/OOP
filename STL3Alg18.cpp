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
    Task("STL3Alg18");
    int n;
    pt >> n;
    deque<int> D(ptin(0), ptin());
    for(int i=0;i<n;i++){
    D.pop_back();
    D.pop_front();
	}
	for(int i=n;i>=1;i--){
    D.push_back(i);
    D.push_front(i);
	}
    //Show(D.begin(), D.end(), "D: ");
    copy(D.begin(), D.end(), ptout());
}
