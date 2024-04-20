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
    Task("STL5Assoc21");
    vector<int> V(ptin(0), ptin());
    multimap<int, int>mymap;
    int x = 0;
    for (int i = 0; i < V.size(); i++)
    {
        x =abs( V[i] % 10);
        mymap.insert({ x,V[i] });
    }
    Show(mymap.begin(), mymap.end());
    for (auto it = mymap.begin(); it != mymap.end(); it++)
    {
        pt << it->first << it->second;
    }
}
