#include <windows.h>
#pragma hdrstop
#include "pt4.h"
using namespace std;
#include <iterator>
#include <vector>
#include <iostream>
typedef ptin_iterator<int> ptin;
typedef ptout_iterator<int> ptout;
void Solve()
{
    Task("STL2Seq10");
    vector<int>L(ptin(0), ptin());
    int x=L.size()/3;
    //Show(L.begin(), L.end(), "L: ");
    for (int i = x-1;i>=0;i--)
    {
        L.push_back(L[i]);
    }
    copy(L.begin(), L.end(), ptout());
}
