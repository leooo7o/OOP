#include "pt4.h"
#include<fstream>
using namespace std;

string getd(char str[80])
{
	string s=str;
	return s.substr(0,2);
}
string getm(char str[80])
{
	string s=str;
	return s.substr(3,2);
}
void Solve()
{
    Task("XFile67");

string s1, s2, s3;
pt >> s1 >> s2 >> s3;
int x;
ifstream f1(s1, ios::binary);
ofstream f2(s2, ios::binary);
ofstream f3(s3, ios::binary);
while (f1.peek() != -1)
{
 char str[80];
 f1.read(str, 80);
 x=stoi(getd(str));
 f2.write((char*)&x,sizeof(x));
 x=stoi(getm(str));
 f3.write((char*)&x,sizeof(x));
}
f1.close();
f2.close();
f3.close();
}
