#include "pt4.h"
using namespace std;

class Validator
{
public:
    virtual string Validate(string s);
};

string Validator::Validate(string s)
{
    return "";
}
class EmptyValidator :public Validator {
public:
    string Validate(string s);
};
string EmptyValidator::Validate(string s) {
    if (s == "") {
        string text;
        text = "!Empty text";
        return text;
    }
    else {
        string text = "";
        return text;
    }
}
class  NumberValidator :public Validator {
public:
    string Validate(string s);
};
bool AllisNum(string str)
{
    if (str.empty())return false;
    for (int i = 0; i < str.size(); i++)
    {
        int tmp = (int)str[i];
        if (tmp >= 48 && tmp <= 57||tmp=='-')
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
string NumberValidator::Validate(string s) {

        if (AllisNum(s))
        {
            string text = "";
            return text;
        }
        else {
            string text = "!'" + s + "': not a number";
            return text;
        }
}
class RangeValidator :public Validator {
private:
    int max;
    int min;
public:
    string Validate(string s);
    RangeValidator(int a, int b);
};
RangeValidator::RangeValidator(int a, int b) {
    min = a;
    max = b;
}
string RangeValidator::Validate(string s) {
    string text;
    int x;
    if (AllisNum(s)) {
        x = stoi(s);
    }
    else {
        text = "!'" + s + "': not in range" + " " + to_string(min) + ".." + to_string(max) + "";
        return text;
    }
    if (x >=min && x <= max) {
        return "";
    }
    else {
        text = "!'" + s + "': not in range" + " " + to_string(min) + ".." + to_string(max) + "";
        return text;
    }
}
// Implement the EmptyValidator, NumberValidator
//   and RangeValidator descendant classes
class TextBox
{
private:
    Validator* v;
    string text;
public:
    TextBox() { v = new Validator; text = ""; }
    void SetText(string s) { text = s; }
    void SetValidator(Validator* h) { v =h; }
    string Validate() {
        string s= v->Validate(text);
        //Show(s);
        return s;
    }
};
class TextForm
{
private:
    vector<TextBox*>tb;
    int n;
public:
    TextForm(int x) { n = x; tb.resize(x); for (int i = 0; i < x; i++) {tb[i]=new TextBox();} }
    void SetText(int ind,string text) {
        tb[ind]->SetText(text);
    }
    void SetValidator(int ind, Validator* v)
    {
        tb[ind]->SetValidator(v);
    }
    string Validate() {
        string s;
        for (int i = 0; i < n; i++) {
                s += tb[i]->Validate();
        }
        return s;
    }
};
// Implement the TextBox and TextForm classes

void Solve()
{
    Task("OOP3Behav4");
    int n, a, b, k;
    pt >> n >> a >> b >> k;
    vector<string>ans;
    vector<TextForm*>v;
    for (int i = 0; i < 5; i++)
    {
        TextForm* a = new TextForm(n);
        v.push_back(a);
    }
    for (int j = 0; j < k; j++)
    {
        char c;
        int x;
        pt >> x >> c;

        if (c == 'N') {
            for (int i = 0; i < 5; i++) {
                v[i]->SetValidator(x, new NumberValidator);
            }
        }
        else if (c == 'E') {
            for (int i = 0; i < 5; i++) {
                v[i]->SetValidator(x, new EmptyValidator);
            }
        }
        else {
            for (int i = 0; i < 5; i++) {
                if(a<=b)
                v[i]->SetValidator(x, new RangeValidator(a,b));
                else
                    v[i]->SetValidator(x, new RangeValidator(b, a));
            }
        }
    }
    string s;
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pt >> s;
            v[i]->SetText(j, s);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        pt << v[i]->Validate();
    }
}
