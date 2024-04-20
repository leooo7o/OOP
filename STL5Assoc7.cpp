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
    Task("STL5Assoc7");
    vector<int> V1(ptin(0), ptin());
    vector<int> V2(ptin(0), ptin());
    multiset<int>set1;
    multiset<int>set2;
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    for (int i = 0; i<V1.size();i++)
    {
        set1.insert(V1[i]);
    }
    for (int i = 0; i<V2.size(); i++)
    {
        set2.insert(V2[i]);
    }
    vector<int> V3(set1.size() + set2.size());
    Show(set1.begin(), set1.end());
    Show(set2.begin(), set2.end());
    auto it=set_symmetric_difference(set1.begin(),set1.end(),set2.begin(),set2.end(),V3.begin());
    V3.resize(it - V3.begin());
    sort(V3.begin(), V3.end(), greater<int>());
   Show(V3.begin(), V3.end());
   for (int i = 0; i < V3.size(); i++)
   {
       pt << V3[i];
   }
}
