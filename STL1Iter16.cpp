#include <windows.h>
#pragma hdrstop
#include "pt4.h"
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <algorithm> 
typedef ptin_iterator<char> ptin;
typedef ptout_iterator<char> ptout;
using namespace std;
bool bools(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    else
        return 0;
}
void Solve()
{
    Task("STL1Iter16");
    replace_copy_if(ptin(0), ptin(), ptout_iterator<char>(), bools,'_');
    //copy(V.begin(), V.end(), ptout());
}
