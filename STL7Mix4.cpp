#include "pt4.h"
using namespace std;

#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
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
    return is >> p.year >> p.month >> p.len >> p.code;
}
void Solve()
{
    Task("STL7Mix4");
    string name1, name2;
    pt >> name1 >> name2;
    ifstream f1(name1.c_str());
    vector<Data> V((istream_iterator<Data>(f1)), istream_iterator<Data>());
    f1.close();
    ShowLine(V.begin(), V.end(), "V: ");

    ofstream f2(name2.c_str());

    f2.close();
}
