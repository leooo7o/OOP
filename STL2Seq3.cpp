#include <windows.h>
#pragma hdrstop
#include "pt4.h"
using namespace std;
#include <iterator>
#include <vector>
typedef ptin_iterator<int> ptin;
typedef ptout_iterator<int> ptout;
void Solve()
{
	Task("STL2Seq3");
	vector<int> V(ptin(0), ptin());
	int tmp;
	for (int i = 0; i < V.size()/2; i++)
	{
		tmp = V[i];
		V[i] = V[V.size()/2+i];
		V[V.size()/2+i]= tmp;
	}
	copy(V.begin(), V.end(), ptout());
	//copy(V.begin() + (V.end() - V.begin()) / 2, V.end() + (V.end() - V.begin()) / 2, ptout());
	//copy(V.begin(), V.begin() + (V.end() - V.begin()) / 2, ptout());
}