#include "pt4.h"
#include<fstream>
using namespace std;

void Solve()
{
    Task("XText34");
    string str;
    string name1, name2 = "$T21$.tmp";
    pt >> name1;
    ifstream f1(name1);
    ofstream f2(name2);
    int num=0;
    while (f1.peek() != -1)
    {
        getline(f1, str);
        num = str.length();
        if (num == 0)
            f2 << endl;
        else {
            str.insert(0, 50 - num, ' ');
            f2 << str << endl;
        }
    }
    f1.close();
    f2.close();
    remove(name1.c_str());
    rename(name2.c_str(), name1.c_str());
}
