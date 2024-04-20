#include "pt4.h"
#include<fstream>
using namespace std;

void Solve()
{
    Task("XText56");
string s;
pt>>s;
ifstream f1(s);
pt>>s;
ofstream f2(s,ios::binary);
char c[126]={0};
int i=0;
while(f1.peek()!=-1)
{
	char cc;
	cc=f1.get();
	int x=cc;
	c[x]=cc;
}
for(int i=125;i>31;i--)
{
	if(c[i]){
		    char cc=c[i];
		f2.write((char*)&cc,sizeof(cc));
	}
}
f1.close();
f2.close();
}
