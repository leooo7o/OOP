#include "pt4.h"
using namespace std;

class TextView
{
    // Do not change the implementation of the class
    int x = 0, y = 0;
    int width = 1, height = 1;
public:
    void GetOrigin(int& x, int& y);
    void SetOrigin(int x, int y);
    void GetSize(int& width, int& height);
    void SetSize(int width, int height);
};
void TextView::GetOrigin(int& x, int& y)
{
    x = this->x;
    y = this->y;
}
void TextView::SetOrigin(int x, int y)
{
    this->x = x;
    this->y = y;
}
void TextView::GetSize(int& width, int& height)
{
    width = this->width;
    height = this->height;
}
void TextView::SetSize(int width, int height)
{
    this->width = width;
    this->height = height;
}

class Shape
{
public:
    virtual string GetInfo() = 0;
    virtual void MoveBy(int a, int b) = 0;
};
class RectShape :public Shape {
private:
    TextView* p;
public:
    RectShape(TextView* p1);
    virtual string GetInfo();
    virtual void MoveBy(int a, int b);
};
RectShape::RectShape(TextView* p1)
{
    p = p1;
}
string RectShape::GetInfo() {
    string s;
    int i1, i2, i3, i4;
    p->GetOrigin(i1, i2);
    p->GetSize(i3, i4);
    string s2 = "(";
    s = "R" + s2 + to_string(i1) + "," + to_string(i2) + ")" + "(" + to_string(i3) + "," + to_string(i4) + ")";
    return s;
}
void RectShape::MoveBy(int a, int b) {
    int i1=0, i2=0;
    p->GetOrigin(i1, i2);
    p->SetOrigin(i1 + a, i2 + b);
    p->GetSize(i1, i2);
    p->SetSize(i1 + a, i2 + b);
}
class TextShape :public Shape {
private:
    TextView* p;
public:
    TextShape(TextView* p1);
    virtual string GetInfo();
    virtual void MoveBy(int a, int b);
};
TextShape::TextShape(TextView* p1)
{
    p = p1;
}
string TextShape::GetInfo() {
    string s;
    int i1, i2, i3, i4;
    p->GetOrigin(i1, i2);
    p->GetSize(i3, i4);
    string s2 = "(";
    s = "T" + s2 + to_string(i1) + "," + to_string(i2) + ")" + "(" + to_string(i3) + "," + to_string(i4) + ")";
    return s;
}
void TextShape::MoveBy(int a, int b) {
    int i1 = 0, i2 = 0;
    p->GetOrigin(i1, i2);
    p->SetOrigin(i1 + a, i2 + b);
    p->GetSize(i1, i2);
    p->SetSize(i1 + a, i2 + b);
}
// Implement the RectShape and TextShape descendant classes

void Solve()
{
    Task("OOP2Struc3");
    int n,a,b;
    pt >> n ;
    vector<char>sig;
    vector<int>itr;
    for (int i = 0; i < n; i++)
    {
        char c;
        int x;
        pt >> c;
        sig.push_back(c);
        pt >> x;
        itr.push_back(x);
        pt >> x;
        itr.push_back(x);
        pt >> x;
        itr.push_back(x);
        pt >> x;
        itr.push_back(x);
    }
    pt >> a >> b;
    for (int i = 0; i < n; i++)
    {
        if (sig[i] == 'T') {
            TextView *a1=new TextView;
            a1->SetOrigin(itr[i * 4], itr[i * 4 + 1]);
            a1->SetSize(itr[i * 4+2], itr[i * 4 + 3]);
            Shape* A = new  TextShape(a1);
            A->MoveBy(a, b);
            pt << A->GetInfo();
        }
        else {
            TextView* a1 = new TextView;
            a1->SetOrigin(itr[i * 4], itr[i * 4 + 1]);
            a1->SetSize(itr[i * 4 + 2], itr[i * 4 + 3]);
            Shape* B = new  RectShape(a1);
            B->MoveBy(a, b);
            pt << B->GetInfo();
        }
    }
}
