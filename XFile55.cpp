#include "pt4.h"
#include<fstream>
using namespace std;

void Solve()
{
	Task("XFile55");
	int n;
	int x;
	int len;
	string s;
	pt >> s;
	fstream out(s, ios::binary | ios::out);
	pt >> n;
	fstream* f = new fstream[n];
	for (int i = 0; i < n; i++) {
		pt >> s;
		f[i].open(s, ios::binary | ios::in);
	}
	for (int i = 0; i < n; i++) {
		len = f[i].tellg();
		out.write((char*)&n, sizeof(n));
		while (f[i].peek()) {
			f[i].read((char*)&n, sizeof(n));
			out.write((char*)&n, sizeof(n));
		}
	}
}