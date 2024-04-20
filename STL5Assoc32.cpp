#include "pt4.h"
using namespace std;

#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <algorithm>

typedef ptin_iterator<string> ptin;
void Solve()
{
    Task("STL5Assoc32");
    vector<string> V1(ptin(0), ptin());
    vector<string> V2(ptin(0), ptin());
    multimap<string, string> mymap;
    for (int i = 0; i < V1.size(); i++)
    {
        char c = V1[i][0];
        for (int j = V2.size()-1; j >= 0; j--)
        {
            if (c == V2[j][V2[j].length() - 1]) {
                mymap.insert({ V1[i],V2[j] });
            }
        }
    }
    vector<string> V3;
    int num = mymap.size();
    pt<<num;
    for (auto it = mymap.begin(); it != mymap.end(); it++)
    {
        pt << it->first << it->second;
    }
}
/*for (auto it = mymap.begin(); it != mymap.end(); it++)
{
    V3.push_back(it->first);
    V3.push_back(it->second);
}
Show(V3.begin(), V3.end());
ptout << V3.size();
copy(V3.begin(), V3.end(), ptout());*/