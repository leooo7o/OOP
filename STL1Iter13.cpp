#include <windows.h>
#pragma hdrstop
#include "pt4.h"
using namespace std;
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include<fstream>
void Solve()
{
	Task("STL1Iter13");
	string s;
	pt >> s;
	ifstream os(s);
	istream_iterator<int> in;
	ptout_iterator<int> out= ptout_iterator<int>();
	for (in = istream_iterator<int>(os); in != istream_iterator<int>(); in++)
	{
		out = *in++;
		if (in == istream_iterator<int>())break;
	}
	//transform(ptin(0), ptin(), ostream_iterator<int>(os, " "),f);
}
