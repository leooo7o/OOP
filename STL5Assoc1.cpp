#include "pt4.h"
using namespace std;

#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <algorithm>
typedef ptin_iterator<int> ptin;
void Solve()
{
    Task("STL5Assoc1");
    vector<int> V(ptin(0), ptin());
    set<int>myset1;
    set<int>::iterator it1;
    set<int>myset2;
    set<int>::iterator it2;
    int x = V.size() / 2;
    sort(V.begin(), V.begin() + x);
    sort(V.begin() + x,V.end());
    for (int i = 0; i < x; i++) {
        int n = V[i];
        it1 = myset1.insert(myset1.end(), n);
    }
    for (int i = x; i < V.size(); i++) {
        int n = V[i];
        it2 = myset2.insert(myset2.end(), n);
    }
    Show(myset1.begin(), myset1.end());
    Show(myset2.begin(), myset2.end());
    bool ret;
    ret = includes(myset1.begin(), myset1.end(), myset2.begin(),myset2.end());
    pt << ret;
}


/*void f1(string s)
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
}*/
