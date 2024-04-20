#include "pt4.h"
#include<fstream>
using namespace std;

void Solve()
{
    Task("XText45");
    string s;
    pt >> s;
    ifstream f(s);
    int num = 0;
    float sum = 0;
    while (f.peek() != -1)
    {
        f >> s;
        if (!f.eof()) {
            int len = s.length();
            for (int i = 0; i < len; i++)
            {
                if (s[i] == '.') {
                    num++;
                    sum += stof(s);
                }
            }
        }
    }
    pt << num << sum;
    f.close();
}
