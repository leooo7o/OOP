#include "pt4.h"
using namespace std;
bool num(string str) {
    if (str == "")return 0;
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= '0' && str[i] <= '9')||str[i]=='-')
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
class AbstractComparable
{
public:
    virtual int CompareTo(AbstractComparable* other) = 0;
    int IndexMax(vector<AbstractComparable*>a) {
        AbstractComparable* ans = a[0];
        int max =0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i]->CompareTo(ans) > 0) {
                max = i;
                ans = a[i];
            }
        }
        return max;
    }
    int LastIndexMax(vector<AbstractComparable*>a) {
        AbstractComparable* ans = a[0];
        int max = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i]->CompareTo(ans) >= 0) {
                max = i;
                ans = a[i];
            }
        }
        return max;
    }
    int IndexMin(vector<AbstractComparable*>a) {
        AbstractComparable* ans = a[0];
        int min = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i]->CompareTo(ans) < 0) {
                min = i;
                ans = a[i];
            }
        }
        return min;
    }
    int   LastIndexMin(vector<AbstractComparable*>a) {
        AbstractComparable* ans = a[0];
        int min = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i]->CompareTo(ans) <= 0) {
                min = i;
                ans = a[i];
            }
        }
        return min;
    }
};
class NumberComparable :public AbstractComparable {
private:
    string text;
public:
    NumberComparable(string s) { text = s; }
    int CompareTo(AbstractComparable* other){
        NumberComparable* a = dynamic_cast<NumberComparable*>(other);
        int x1, x2;
        if (num(text)) {
            x1 = stoi(text);
        }
        else x1 = 0;
        if (num(a->text)) {
            x2 = stoi(a->text);
        }
        else x2 = 0;
        if (x1 > x2)
            return 1;
        else if (x1 < x2)
            return -1;
        else
            return 0;
    }
};
class LengthComparable :public AbstractComparable {
private:
    string text;
public:
    LengthComparable(string s) { text = s; }
    int CompareTo(AbstractComparable* other) {
        LengthComparable* a= dynamic_cast<LengthComparable*>(other);
        if (this->text.length() > a->text.length())
            return 1;
        else if(this->text.length()< a->text.length())
            return -1;
        else
            return 0;
    }
};

class TextComparable :public AbstractComparable {
private:
    string text;
public:
    TextComparable(string s) { text = s; }
    int CompareTo(AbstractComparable* other) {
        TextComparable* a = dynamic_cast<TextComparable*>(other);
        if (this->text > a->text)
            return 1;
        else if (this->text == a->text)
            return 0;
        else
            return -1;
    }
};
// Implement the NumberComparable, LengthComparable
//   and TextComparable descendant classes

void Solve()
{
    Task("OOP3Behav6");
    int n, k;
    pt >> n >> k;
    for (int i = 0; i < k; i++)
    {
        string c;
        pt >> c;
        vector<AbstractComparable*> V;
        for (int j = 0; j < n; j++) {
            string s;
            pt >> s;
            AbstractComparable* a;
            if (c == "N")
            {
                a= new NumberComparable(s);
            }
            else if (c == "L")
            {
                a = new LengthComparable(s);
            }
            else {
                a = new TextComparable(s);
            }
            V.push_back(a);
        }
        pt << V[0]->IndexMax(V) << V[0]->LastIndexMax(V) << V[0]->IndexMin(V) << V[0]->LastIndexMin(V);
    }
}
