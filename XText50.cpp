#include "pt4.h"
#include<fstream>
using namespace std;

void Solve()
{
    Task("XText50");
    string s,str;
    pt >> s;
    ifstream f1(s);
    pt >> s;
    ofstream f2(s,ios::binary);
    pt >> s;
    ofstream f3(s,ios::binary);
    double x;
    char c;
    while (f1.peek() != -1)
    {
        getline(f1,str);
        for(int i=0;i<30;i++)
        {
        	c=str[i];
        	f2.write((char*)&c,sizeof(c));
        	Show(i);
        	        Show(c);
		}
	c='\0';
	      f2.write((char*)&c,50);
//	      	c='\n';
//	      f2.write((char*)&c,sizeof(c));
        s = str.substr(30, str.length()-30);
        x = stof(s);
        Show(x);
        f3.write((char*)&x, sizeof(x));
    }
    f1.close();
    f2.close();
    f3.close();
}
