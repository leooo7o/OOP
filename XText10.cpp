#include "pt4.h"
#include<fstream>
using namespace std;

void Solve()
{
    Task("XText10");
    int k;
 string name,s, name2 = "$T21$.tmp";
 //s0.clear();
pt>>k>>name;
ifstream f1(name);
ofstream f2(name2);
while(f1.peek()!=-1)
{
	getline(f1,s);
	if (k == 0)
		f2  << endl;
	f2 << s<<endl;
	k--;
}
f1.close();
f2.close();
remove(name.c_str());
rename(name2.c_str(),name.c_str());
}
