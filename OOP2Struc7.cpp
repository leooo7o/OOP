#include "pt4.h"
using namespace std;

class Component
{
public:
    virtual string Show() = 0;
};
class ConcreteComponent :public Component {
public:
    virtual string Show();
    ConcreteComponent(string s);
private:
    string info;
};
ConcreteComponent::ConcreteComponent(string s) {
    this->info = s;
}
string ConcreteComponent::Show() {
    return info;
}
// Implement the ConcreteComponent descendant class

class Decorator : public Component
{
protected:
    Component* comp;
};
class ConcreteDecoratorA :public Decorator {
public:
    ConcreteDecoratorA(Component* p1);
    string Show();
};
ConcreteDecoratorA::ConcreteDecoratorA(Component* p1) {
    this->comp = p1;
}
string ConcreteDecoratorA::Show() {
    string s;
    s = "==" + comp->Show() + "==";
    return s;
}
class ConcreteDecoratorB :public Decorator {
public:
    ConcreteDecoratorB(Component* p1);
    string Show();
};
ConcreteDecoratorB::ConcreteDecoratorB(Component* p1) {
    this->comp = p1;
}
string ConcreteDecoratorB::Show() {
    string s;
    s = "(" + comp->Show() + ")";
    return s;
}
// Implement the ConcreteDecoratorA
//   and ConcreteDecoratorB descendant classes

void Solve()
{
    Task("OOP2Struc7");
    int n;
    pt >> n;
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        pt >> s1 >> s2;
        Component* a = new ConcreteComponent(s1);
        for (int j = 0; j < s2.size(); j++)
        {
            if (s2[j] == 'A')
                a = new ConcreteDecoratorA(a);
            else
                a = new ConcreteDecoratorB(a);
        }
        ans.push_back(a->Show());
    }
    for (int i=ans.size()-1;i>=0;i--)
    {
        pt << ans[i];
    }
}
