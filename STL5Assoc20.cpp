#include "pt4.h"
using namespace std;

#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <algorithm>

typedef ptin_iterator<string> ptin;
map<char, multiset<string>> M;
void f1(string s)
{
	M[s[0]].insert(s);
}
void f2(pair<char, multiset<string>> p)
{
	pt << p.first;
	copy(p.second.begin(), p.second.end(),
		ptout_iterator<string>());
}
void Solve()
{
	Task("STL5Assoc20");
	vector<string> V(ptin(0), ptin());
	for_each(V.begin(), V.end(), f1);
	for_each(M.begin(), M.end(), f2);
}

