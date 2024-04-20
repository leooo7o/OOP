#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <functional>
typedef ptin_iterator<string> ptin;

void Solve()
{
    Task("STL3Alg59");
    string s;
    vector<string> V(ptin(0), ptin());
    for (int i = V.size() - 1; i >= 0; i--)
    {
        
        s += V[i][0];
    }
    for(int i = 0; i < V.size(); i++)
    {
        int x = V[i].length();
        s += V[i][x-1];
    }
    Show(s);
    pt << s;
}
