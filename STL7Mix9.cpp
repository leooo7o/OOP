#include "pt4.h"
using namespace std;

#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <locale>
#include <windows.h>
#include "Windows.h"
struct Data
{
    int code, year, month, len;
    operator string()
    {
        ostringstream os;
        os << "{ code = " << code << ", year = " << year
            << ", month = " << month << ", len = " << len << " }";
        return os.str();
    }
};

istream& operator>>(istream& is, Data& p)
{
    return is >> p.code >> p.len >> p.month >> p.year;
}
void Solve()
{
    Task("STL7Mix9");
    int k;
    pt >> k;
    string name1, name2;
    pt >> name1 >> name2;
    ifstream f1(name1.c_str());
    vector<Data> V((istream_iterator<Data>(f1)), istream_iterator<Data>());
    f1.close();
    map<int, int> mymap;
    int ptr = 0;
    for (int i = 0; i < V.size(); i++)
    {
        if (V[i].code == k) {
            ptr = 1;
                mymap.insert({ V[i].year,0 });
        }
    }
    for (int i = 0; i < V.size(); i++)
    {
        if (V[i].code == k) {
            if (V[i].len >15) {
                mymap[V[i].year]++;
            }
        }
    }
    Show(mymap.begin(), mymap.end());
    multimap<int, int> mymap2;
    for (auto it = mymap.rbegin(); it != mymap.rend(); it++)
    {
        mymap2.insert({ it->second,it->first });
    }
    Show(mymap2.begin(), mymap2.end());
    ofstream f2(name2.c_str());
    if (ptr == 0) {
        f2 << "No data";
    }
    else {
        for (auto it = mymap2.rbegin(); it != mymap2.rend(); it++)
        {
            f2 << it->first << " " << it->second << endl;
        }
    }
    f2.close();
}
