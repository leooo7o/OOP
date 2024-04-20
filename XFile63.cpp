#include "pt4.h"
#include<fstream>
using namespace std;

void Solve()
{
    Task("XFile63");
int k;
string s1, s2, s3;
pt >> k >> s1 >> s2 >> s3;
ifstream f1(s1, ios::binary);
ofstream f2(s2, ios::binary),
 f3(s3, ios::binary);
while (f1.peek() != -1)
{
 char s[80];
 char c = ' ';
 f1.read(s, 80);
 if (strlen(s) >= k)
 {
 s[k] = '\0';
 c = s[k - 1];
 }
 f2.write(s, 80);
 f3.write((char *)&c, 1);
}
f1.close();
f2.close();
f3.close();
}
