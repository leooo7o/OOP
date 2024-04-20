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
bool bools(int i) {
    return (i <= 0);
}
void Solve()
{
    Task("STL3Alg29");
    vector<int> V(ptin(0), ptin());
    vector<int> Vn(100);
    vector<int>::iterator it = V.begin();
    for (int i = 0; i < V.size() / 2; i++)
    {
        it++;
    }
    remove_copy_if(it, V.end(), Vn.begin(), bools);
    for (int i = 99; i >= 0; i--) {
        if (Vn[i] > 0)
            V.insert(V.begin(), Vn[i]);
    }
    Show(Vn.begin(), Vn.end(), "Vn: ");
    Show(V.begin(), V.end(), "V: ");
    copy(V.begin(), V.end(), ptout());
}
