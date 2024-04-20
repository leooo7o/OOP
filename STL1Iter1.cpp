#include "pt4.h"
using namespace std;
typedef ptin_iterator<int> ptin;
typedef ptout_iterator<int> ptout;
void Solve()
{
    Task("STL1Iter1");
int count=0;
vector<int> vec(ptin(0), ptin());
for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == 0)
        count++;
}
pt << count;
}
