#include "pt4.h"
#include<functional>
using namespace std;

#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include<functional>
struct Data
{
    int num, year;
    string fam;
    operator string()
    {
        ostringstream os;
        os << "{ num = " << num << ", year = " << year
            << ", fam = " << fam << " }";
        return os.str();
    }
};

istream& operator>>(istream& is, Data& p)
{
    return is >> p.fam >> p.num >> p.year;
}
struct greater_less {
    bool operator()(const pair<int, int>& a1, const pair<int, int>& a2) {
        if (a1.first == a2.first)
            return a2.second < a1.second;
        else
            return a2.first > a1.first;
    }
};
void Solve()
{
    Task("STL7Mix24");
    string name1, name2;
    pt >> name1 >> name2;
    ifstream f1(name1.c_str());
    vector<Data> V((istream_iterator<Data>(f1)), istream_iterator<Data>());
    f1.close();
    map<pair<int, int>,vector<string>, greater_less> mymap;
    for (auto e:V)
    {
    	if(mymap[pair<int, int>(e.num, e.year)].size()<3)
        mymap[pair<int, int>(e.num, e.year)].push_back(e.fam);
    }
    Show(mymap.begin(), mymap.end());
    ofstream f2(name2.c_str());
    for(auto e:mymap)
    {
   	
		{
    	f2<<e.first.first<<" "<<e.first.second<<" ";
    	for(int i=0;i<e.second.size();i++)
    	{
    		if(i==e.second.size()-1)
    		f2<<e.second[i];
    		else
    		f2<<e.second[i]<<" ";
		}
		f2<<endl;
		}
	}
    f2.close();
}
