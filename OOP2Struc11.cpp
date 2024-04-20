#include "pt4.h"
#include <map>
#include <string>
using namespace std;

class Flyweight
{
public:
    virtual char Show(bool state) = 0;
};
class ConcreteFlyweight:public Flyweight {
public:
    virtual char Show(bool state);
    ConcreteFlyweight() {};
};
char ConcreteFlyweight::Show(bool state) {
    if (state == 1)
        return 'A';
    else
        return 'a';
}
class UnsharedConcreteFlyweight :public Flyweight {
private:
    char inf;
public:
    UnsharedConcreteFlyweight(char c);
    virtual char Show(bool state);
};
UnsharedConcreteFlyweight::UnsharedConcreteFlyweight(char c) {
    this->inf = c;
}
char UnsharedConcreteFlyweight::Show(bool state) {
    if ((state == 1 && inf <= 'Z' && inf >= 'A') || (state == 0 && inf <= 'z' && inf >= 'a'))
        return inf;
    else if ((state == 1 && inf <= 'z' && inf >= 'a'))
        return inf - 'a' + 'A';
    else
        return inf +'a' - 'A';
}
// Implement the ConcreteFlyweight
//   and UnsharedConcreteFlyweight descendant classes
class FlyweightFactory {
private:
    map<char,Flyweight*>cf;
    int count;
public:
    FlyweightFactory() { cf.clear(); count = 0; };
    Flyweight* CreateFlyweight(char inf);
    int getCount();
};
Flyweight* FlyweightFactory::CreateFlyweight(char inf) {
        if (cf.find(inf) != cf.end()) {
            if (inf == 'a' || inf == 'A') { return cf[inf]; }
            else {
                count++;
                return cf[inf];
            }
        }
        else {
            if (inf == 'a') { if (cf.find('A') != cf.end()) { Flyweight* fly = new UnsharedConcreteFlyweight(inf);  cf[inf] = fly; return cf[inf]; } else { count++; Flyweight* fly = new UnsharedConcreteFlyweight(inf);  cf[inf] = fly; return cf[inf]; } }
            if (inf == 'A') { if (cf.find('a') != cf.end()) { Flyweight* fly = new UnsharedConcreteFlyweight(inf);  cf[inf] = fly; return cf[inf]; } else { count++; Flyweight* fly = new UnsharedConcreteFlyweight(inf);  cf[inf] = fly; return cf[inf]; } }
            else {
                count++;
                Flyweight* fly = new UnsharedConcreteFlyweight(inf);
                cf[inf] = fly;
                return fly;
            }
        }
}
int FlyweightFactory::getCount() {
    return this->count;
}
class Client {
private:
    FlyweightFactory* f;
    vector<Flyweight*>fw;
public:
    Client() {
        f = new FlyweightFactory; //fw.resize(30); /*for (int i = 0; i < 30; i++) {
            //fw[i] = new UnsharedConcreteFlyweight();*/
    };
    void MakeFlyweights(string inf);
    string ShowFlyweights(bool state);
    int GetFlyweightCount();
    void del();
};
void Client::MakeFlyweights(string inf)
{
    for (int i = 0; i < inf.length(); i++)
    {
        fw.push_back(f->CreateFlyweight(inf[i]));
    }
}
void Client::del()
{
    fw.clear();
}
string Client::ShowFlyweights(bool state) {
    string s;
    for (int i = 0; i < fw.size(); i++)
    {
        s += fw[i]->Show(state);
    }
    return s;
}
int Client::GetFlyweightCount()
{
    return f->getCount();
}
// Implement the FlyweightFactory and Client classes

void Solve()
{
    Task("OOP2Struc11");
    Client* a = new Client;
    for (int i = 0; i < 5; i++) {
        string s;
        pt >> s;
        a->del();
        a->MakeFlyweights(s);
        pt << a->ShowFlyweights(1) << a->ShowFlyweights(0) << a->GetFlyweightCount();
    }
}
