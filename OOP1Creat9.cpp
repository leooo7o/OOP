#include "pt4.h"
using namespace std;

class Builder
{
public:
    virtual void BuildStart() {}
    virtual void BuildPartA() {}
    virtual void BuildPartB() {}
    virtual void BuildPartC() {}
    virtual string GetResult() = 0;
};
class ConcreteBuilder1 :public Builder {
private:
    string info;
public:
    virtual void BuildStart() { info = ""; };
    virtual void BuildPartA(){ info += "-1-"; };
    virtual void BuildPartB(){ info += "-2-"; };
    virtual void BuildPartC(){ info += "-3-"; };
    virtual string GetResult();
};
string ConcreteBuilder1::GetResult() {
    return info;
}
class ConcreteBuilder2 :public Builder {
private:
    string info;
public:
    virtual void BuildStart() { info = ""; }
    virtual void BuildPartA() {info += "="; for (int i = 0; i < 1; i++) { info += "*"; } info += "=";};
    virtual void BuildPartB() { info += "="; for (int i = 0; i < 2; i++) { info += "*"; } info += "="; };
    virtual void BuildPartC() { info += "="; for (int i = 0; i < 3; i++) { info += "*"; } info += "="; };
    virtual string GetResult();
};
string ConcreteBuilder2::GetResult() {
    return info;
}
// Implement the ConcreteBuilder1
//   and ConcreteBuilder2 descendant classes

class Director
{
    Builder* b;
public:
    Director(Builder* b);
    string GetResult();
    void Construct(string templat);
};

Director::Director(Builder* b)
{
    this->b = b;
}
string Director::GetResult()
{
    return b->GetResult();
}
void Director::Construct(string templat)
{
    for (int i = 0; i < templat.length(); i++)
    {
        if (templat[i] == 'A')
            b->BuildPartA();
        else if (templat[i] == 'B')
            b->BuildPartB();
        else if(templat[i] == 'C')
            b->BuildPartC();
    }
    // Implement the method
}

void Solve()
{
    Task("OOP1Creat9");
    for (int i = 0; i < 5; i++)
    {
        string s;
        pt >> s;
        Builder*a1=new ConcreteBuilder1;
        Builder*a2=new ConcreteBuilder2;
        Director* A = new Director(a1);
        Director* B = new Director(a2);
        A->Construct(s);
        B->Construct(s);
        pt << A->GetResult();
        pt << B->GetResult();
        delete A, B, a1, a2;
    }
}
