#include "pt4.h"
using namespace std;

class AbstractButton
{
public:
    virtual string GetControl() = 0;
};
class Button1 :public AbstractButton {
private:
    string s;
public:
    Button1(string text) { s = text; }
    virtual string GetControl();
};
string Button1::GetControl() {
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] + 'A' - 'a';
    }
    string text = "[" + s + "]";
    return text;
}
class Button2 :public AbstractButton {
private:
    string s;
public:
    Button2(string text) {s = text;}
    virtual string GetControl();
};
string Button2::GetControl() {
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 'a' - 'A';
    }
    string text = "<" + s + ">";
    return text;
}
// Implement the Button1 and Button2 descendant classes
class AbstractLabel
{
public:
    virtual string GetControl() = 0;
};
class Label1 :public AbstractLabel {
private:
    string s;
public:
    Label1(string text) {s = text;}
    virtual string GetControl();
};
string Label1::GetControl() {
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] + 'A' - 'a';
    }
    string text = "=" + s + "=";
    return text;
}
class Label2 :public AbstractLabel {
private:
    string s;
public:
    Label2(string text) {s = text;}
    virtual string GetControl();
};
string Label2::GetControl() {
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 'a' - 'A';
    }
    string text = "\"" + s + "\"";
    return text;
}
// Implement the Label1 and Label2 descendant classes
class ControlFactory
{
public:
    virtual AbstractButton* CreateButton(string text) = 0;
    virtual AbstractLabel* CreateLabel(string text) = 0;
};
class Factory1 :public ControlFactory {
    virtual AbstractButton* CreateButton(string text);
    virtual AbstractLabel* CreateLabel(string text);
};
AbstractButton* Factory1::CreateButton(string text) {
    AbstractButton* a1 = new Button1(text);
    return a1;
}
AbstractLabel* Factory1::CreateLabel(string text) {
    AbstractLabel* a1 = new Label1(text);
    return a1;
}
class Factory2 :public ControlFactory {
    virtual AbstractButton* CreateButton(string text);
    virtual AbstractLabel* CreateLabel(string text);
};
AbstractButton* Factory2::CreateButton(string text) {
    AbstractButton* a1 = new Button2(text);
    return a1;
}
AbstractLabel* Factory2::CreateLabel(string text) {
    AbstractLabel* a1 = new Label2(text);
    return a1;
}
// Implement the Factory1 and Factory2 descendant classes

class Client
{
    ControlFactory* m_f;
    string s;
    // Add required fields
public:
    Client(ControlFactory* f);
    void AddButton(string text);
    void AddLabel(string text);
    string GetControls();
};

Client::Client(ControlFactory* f)
{
    m_f = f;
    // Implement the constructor
}
void Client::AddButton(string text)
{
    AbstractButton* a = m_f->CreateButton(text);
    s=a->GetControl();
    // Implement the method
}
void Client::AddLabel(string text)
{
    AbstractLabel* a = m_f->CreateLabel(text);
    s = a->GetControl();
    // Implement the method
}
string Client::GetControls()
{
    //string text = "what";
    //return text;
    return s;
    // Remove the previous statement and implement the method
}

void Solve()
{
    Task("OOP1Creat5");
    int n;
    pt >> n;
    vector<string>V;
    for (int i = 0; i<n; i++)
    {
        string s;
        pt >> s;
        V.push_back(s);
    }    
    string ans="";
    for (int i = 0; i < n; i++) {
        if (V[i][0] == 'B') {
            Client* p = new Client(new Factory1);
            p->AddButton(V[i].substr(2));
            ans += p->GetControls();
            ans += " ";
        }
        else if (V[i][0] == 'L') {
            Client* p = new Client(new Factory1);
            p->AddLabel(V[i].substr(2));
            ans += p->GetControls();
            ans += " ";
        }
    }
    ans[ans.length()-1] = 0;
    pt << ans;
    string ans2="";
    for (int i = 0; i<n; i++) {
        if (V[i][0] == 'B') {
            Client* p = new Client(new Factory2);
            p->AddButton(V[i].substr(2));
            ans2 += p->GetControls();
            ans2 += " ";
        }
        else if (V[i][0] == 'L') {
            Client* p = new Client(new Factory2);
            p->AddLabel(V[i].substr(2));
            ans2 += p->GetControls();
            ans2 += " ";
        }
    }
    ans2[ans2.length()-1] = 0;
    pt << ans2;
}
