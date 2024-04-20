#include "pt4.h"
#include<fstream>
using namespace std;

void Solve()
{
    Task("XText41");
    fstream* f = new fstream[4];
    string s1,s2,s3;
    string s;
    int x1=0,x2=0,x3=0;
    pt >> s;
    ifstream f1(s,ios::binary);
    pt >> s;
    ifstream f2(s,ios::binary);
    pt >> s;
    ifstream f3(s,ios::binary);
    pt >> s;
    ofstream f4(s);
    while (f1.peek() != -1)
    {
        f1.read((char*)&x1, sizeof(x1));
        f2.read((char*)&x2, sizeof(x2));
        f3.read((char*)&x3, sizeof(x3));
        s1 = to_string(x1);
        s2 = to_string(x2);
        s3 = to_string(x3);
        s1.resize(20, ' ');
        s2.resize(20, ' ');
        s3.resize(20, ' ');
        s = "|" + s1 + s2+ s3 + "|";
        Show(s);
        f4 << s<< endl;
    }
    f1.close();
    f2.close();
    f3.close();
    f4.close();
}
