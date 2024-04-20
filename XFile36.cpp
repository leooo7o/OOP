#include "pt4.h"
#include<fstream>
using namespace std;

void Solve()
{
    Task("XFile36");
    string s1, s2 = "$F25$.tst";
    pt >> s1;
    ifstream f1(s1, ios::binary);
    ofstream f2(s2, ios::binary);
    int x;
    while (f1.peek() != -1)
    {
        f1.read((char*)&x, sizeof(x));
        f2.write((char*)&x, sizeof(x));
    }
    f1.seekg(0, ios::beg);
    while (f1.peek() != -1)
    {
        f1.read((char*)&x, sizeof(x));
        f2.write((char*)&x, sizeof(x));
    }
    f1.close();
    f2.close();
    remove(s1.c_str());
    rename(s2.c_str(), s1.c_str());
}