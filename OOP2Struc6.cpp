#include "pt4.h"
using namespace std;

class Device
{
public:
    virtual void Add(Device* d) {}
    virtual string GetName() = 0;
    virtual int GetTotalPrice() = 0;
};
class SimpleDevice :public Device {
private:
    string name;
    int price;
public:
    SimpleDevice(string str, int x) { name = str; price = x; }
    virtual void Add(Device* d);
    virtual string GetName();
    virtual int GetTotalPrice();
};
void  SimpleDevice::Add(Device* d) {
}
string SimpleDevice::GetName() {
    return this->name;
}
int SimpleDevice::GetTotalPrice() {
    return this->price;
}
class CompoundDevice :public Device {
private:
    string name;
    int price;
public:
    CompoundDevice(string str, int x) { name = str; price = x;}
    virtual void Add(Device* d);
    virtual string GetName();
    virtual int GetTotalPrice();
private:
    vector<Device*>m;
};
void  CompoundDevice::Add(Device* d) {
    this->m.push_back(d);
}
string CompoundDevice::GetName() {
    return this->name;
}
int CompoundDevice::GetTotalPrice() {
    int x=price;
    for (auto i : m) { x += i->GetTotalPrice(); }
    return x;
}
// Implement the SimpleDevice
//   and CompoundDevice descendant classes

void Solve()
{
    Task("OOP2Struc6");
    int n;
    pt >> n;
    vector<string>v1;
    vector<int> v2;
    vector<int> v3;
    vector<Device*>v4;
    vector<Device*>v5;
    for (int i = 0; i < n; i++)
    {
        string s;
        int x;
        pt >> s >> x;
        v1.push_back(s);
        v2.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        pt >> x;
        v3.push_back(x);
        Device* com = new CompoundDevice(v1[i], v2[i]);
        Device* p = new SimpleDevice(v1[i], v2[i]);
        v4.push_back(com);
        v5.push_back(p);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j =0; j < n; j++)
        {
            if (i == v3[j])
            {
                v4[i]->Add(v4[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v1[i][0] >= 'a' && v1[i][0] <= 'z') {
            pt << v5[i]->GetName() << v5[i]->GetTotalPrice();
        }
        else
            pt << v4[i]->GetName() << v4[i]->GetTotalPrice();
    }
}
