#include "pt4.h"
using namespace std;

#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <algorithm>

typedef ptin_iterator<int> ptin;
map<int,vector<int>> M;
void Solve()
{
    Task("STL5Assoc33");
    vector<int> V1(ptin(0), ptin());
    vector<int> V2(ptin(0), ptin());
    for (auto i = V1.begin(); i < V1.end(); i++)
    {
        //vector<int>tmp;
        //copy_if(V2.begin(), V2.end(), tmp.begin(), [](int a, int b) {return (a % 2) == (b % 2); });
        //Show(tmp);
    }
}
