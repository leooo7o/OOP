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
    Task("STL5Assoc15");
    vector<int> V(ptin(0), ptin());
    map<int, int>mymap;
    int x=0;
    for (int i = 0; i < V.size(); i++)
    {
        x = V[i];
        mymap.insert({ x, 0 });
    }
    x = 0;
    for (int i = 0; i < V.size(); i++)
    {
        mymap[V[i]]++;
    }
    Show(mymap.begin(), mymap.end());
    for (auto it = mymap.begin(); it != mymap.end(); it++)
    {
        pt << it->first << it->second;
    }
}
