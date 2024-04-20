#include "pt4.h"
#include<fstream>
using namespace std;

void Solve()
{
    Task("XFile25");
    string s;
    pt >> s;
    fstream f(s, ios::binary | ios::in | ios::out);
    f.seekg(0, ios::end);
    int len = f.tellg(),
        size = sizeof(double);
    f.seekg(0);
    for (int i = 0; i < len / size; ++i)
    {
        f.seekg(f.tellg());
        double x;
        f.read((char*)&x, size);
        x = x * x;
        f.seekg(size * i);
        f.write((char*)&x, size);
    }
    f.close();
}
