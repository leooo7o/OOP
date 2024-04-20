#include "pt4.h"
#include <algorithm>
using namespace std;
class Product
{
public:
    virtual string GetInfo() = 0;
    virtual void Transform() = 0;
};

// ÐÅÀËÈÇÓÉÒÅ ÊËÀÑÑÛ-ÏÎÒÎÌÊ?ConcreteProduct1 ?ConcreteProduct2

class Creator
{
protected:
    virtual Product* FactoryMethod(string info) = 0;
public:
    string AnOperation(string info);
};

string Creator::AnOperation(string info)
{
    Product* p = FactoryMethod(info);
    p->Transform();
    p->Transform();
    string s = p->GetInfo();
    delete p;
    return s;
}
void ConcreteProduct1::Transform()
{
    info = transf(info, " ", ' ');
}
void ConcreteProduct2::Transform()
{
    info = transf(info, "**", '*');
}
string transf(string s, string subs, char c)
{
    string res = "";
    for (size_t i = 0; i < s.length() - 1; i++)
    {
        res += s[i];
        if (s[i] != c)
            res += subs;
    }
    return res + s[s.length() - 1];
}
class ConcreteProduct1 : public Product
{
    string info;
public:
    ConcreteProduct1(string info);
    string GetInfo() override;
    void Transform() override;
};
class ConcreteProduct2 : public Product
{
    string info;
public:
    ConcreteProduct2(string info);
    string GetInfo() override;
    void Transform() override;
};
string ConcreteProduct1::GetInfo()
{
    return info;
}
string ConcreteProduct2::GetInfo()
{
    return info;
}

// ÐÅÀËÈÇÓÉÒÅ ÊËÀÑÑÛ-ÏÎÒÎÌÊ?ConcreteCreator1 ?ConcreteCreator2;
//   ÌÅÒÎ?AnOperation ÏÅÐÅÎÏÐÅÄÅËßÒÜ ?ÍÈ?ÍÅ ÒÐÅÁÓÅÒÑ?
class ConcreteCreator1 : public Creator
{
protected:
    Product* FactoryMethod(string info) override;
};
class ConcreteCreator2 : public Creator
{
protected:
    Product* FactoryMethod(string info) override;
};
Product* ConcreteCreator1::FactoryMethod(string info)
{
    return new ConcreteProduct1(info);
}
Product* ConcreteCreator2::FactoryMethod(string info)
{
    return new ConcreteProduct2(info);
}

void Solve()
{
Task("OOP1Creat1");
ConcreteCreator1 c1;
ConcreteCreator2 c2;
for (int i = 0; i < 5; i++)
{
string s;
pt >> s;
pt << c1.AnOperation(s) << c2.AnOperation(s);
}
}
