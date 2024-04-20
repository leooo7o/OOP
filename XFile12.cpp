#include "pt4.h"
#include<fstream>
using namespace std;

void Solve()
{
    Task("XFile12");
    fstream *f = new fstream[3];
    for (int i = 0; i < 3; ++i)
    {
        string s;
        pt >> s;
        if (i < 1)
            f[i].open(s, ios::binary | ios::in);
        else
            f[i].open(s, ios::binary | ios::out);
    }
   int x=0;
   while (f[0].peek() != -1)
   {
        f[0].read((char*)&x, sizeof(x));
        if(x%2==0)
        f[1].write((char*)&x, sizeof(x));
        else f[2].write((char*)&x, sizeof(x));
   }
        for (int i = 0; i < 3; ++i)
            f[i].close();
        delete[] f;
}
