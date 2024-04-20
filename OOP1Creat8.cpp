#include "pt4.h"
using namespace std;

class AbstractGraphic
{
public:
    virtual AbstractGraphic* Clone() = 0;
    virtual void ChangeLocation(int x1, int y1, int x2, int y2) = 0;
    virtual string Draw() = 0;
};
class Ellip :public AbstractGraphic {
public:
    virtual AbstractGraphic* Clone();
    virtual void ChangeLocation(int x1, int y1, int x2, int y2);
    virtual string Draw();
private:
    int m1;
    int n1;
    int m2;
    int n2;
};
AbstractGraphic* Ellip::Clone(){
    return new Ellip(*this);
}
void Ellip::ChangeLocation(int x1, int y1, int x2, int y2) {
    m1 = x1;
    n1 = y1;
    m2 = x2;
    n2 = y2;
}
string Ellip::Draw() {
    string s1="(";
    string s2 = ")";
    s1 = "Ellip" + s1 + to_string(m1)+"," + to_string(n1) + ","+to_string(m2)+"," + to_string(n2) + s2;
    return s1;
}
class Line :public AbstractGraphic {
public:
    virtual AbstractGraphic* Clone();
    virtual void ChangeLocation(int x1, int y1, int x2, int y2);
    virtual string Draw();
private:
    int m1;
    int n1;
    int m2;
    int n2;
};
AbstractGraphic* Line::Clone() {
    return new Line(*this);
}
void Line::ChangeLocation(int x1, int y1, int x2, int y2) {
    m1 = x1;
    n1 = y1;
    m2 = x2;
    n2 = y2;
}
string Line::Draw() {
    string s1 = "(";
    string s2 = ")";
    s1 = "Line" + s1 + to_string(m1) + "," + to_string(n1) + "," + to_string(m2) + "," + to_string(n2)  + s2;
    return s1;
}
class Rect :public AbstractGraphic {
public:
    virtual AbstractGraphic* Clone();
    virtual void ChangeLocation(int x1, int y1, int x2, int y2);
    virtual string Draw();
private:
    int m1;
    int n1;
    int m2;
    int n2;
};
AbstractGraphic* Rect::Clone() {
    return new Rect(*this);
}
void Rect::ChangeLocation(int x1, int y1, int x2, int y2) {
    m1 = x1;
    n1 = y1;
    m2 = x2;
    n2 = y2;
}
string Rect::Draw() {
    string s1 = "(";
    string s2 = ")";
    s1 = "Rect" +s1 + to_string(m1) + "," + to_string(n1) + "," + to_string(m2) + "," + to_string(n2) + s2;
    return s1;
}
// Implement the Ellip, Line and Rect descendant classes

class GraphEditor
{
    AbstractGraphic* a1;
    AbstractGraphic* a2;
    int sym;
    // Add required fields
public:
    GraphEditor(AbstractGraphic* p1, AbstractGraphic* p2);
    ~GraphEditor();
    void AddGraphic(int np, int x1, int y1, int x2, int y2);
    string DrawAll();
};

GraphEditor::GraphEditor(AbstractGraphic* p1, AbstractGraphic* p2)
{
    a1 = p1;
    a2 = p2;
    // Implement the constructor
}
GraphEditor::~GraphEditor()
{
    delete a1;
    delete a2;
    // Implement the destructor
}
void GraphEditor::AddGraphic(int np, int x1, int y1, int x2, int y2)
{
    if (np == 1) {
        a1->ChangeLocation(x1, y1, x2, y2);
        sym = 1;
    }
    else
    {
        a2->ChangeLocation(x1, y1, x2, y2);
        sym = 0;
    }
    // Implement the method
}
string GraphEditor::DrawAll()
{
    if(sym==1)
    return a1->Draw();
    else
    return a2->Draw();
    //return "";
    // Remove the previous statement and implement the method
};

void Solve()
{
    Task("OOP1Creat8");
    string s;
    int n;
    pt >> s >> n;
    int np, x1, y1, x2, y2;
    string sum;
    if (s == "LE")
    {
        AbstractGraphic* p1 = new Line();
        AbstractGraphic* p2 = new Ellip();
        for (int i = 0; i < n; i++)
        {
            pt >> np >> x1 >> y1 >> x2 >> y2;
            AbstractGraphic*A=p1->Clone();
            AbstractGraphic*B =p2->Clone();
            GraphEditor* mp = new GraphEditor(A, B);
            mp->AddGraphic(np, x1, y1, x2, y2);
            if(i>0)
            sum = sum + " " + mp->DrawAll();
            else
                sum = sum + mp->DrawAll();
            delete mp;
        }
    }
    else if (s == "EL") {
        AbstractGraphic* p1 = new Ellip;
        AbstractGraphic* p2 = new Line;
        for (int i = 0; i < n; i++)
        {
            pt >> np >> x1 >> y1 >> x2 >> y2;
            AbstractGraphic* A = p1->Clone();
            AbstractGraphic* B = p2->Clone();
            GraphEditor* mp = new GraphEditor(A, B);
            mp->AddGraphic(np, x1, y1, x2, y2);
            if (i > 0)
                sum = sum + " " + mp->DrawAll();
            else
                sum = sum + mp->DrawAll();
            delete mp;
        }
    }
    else if (s == "RE")
    {
        AbstractGraphic* p1 = new Rect;
        AbstractGraphic* p2 = new Ellip;
        for (int i = 0; i < n; i++)
        {
            pt >> np >> x1 >> y1 >> x2 >> y2;
            AbstractGraphic* A = p1->Clone();
            AbstractGraphic* B = p2->Clone();
            GraphEditor* mp = new GraphEditor(A, B);
            mp->AddGraphic(np, x1, y1, x2, y2);
            if (i > 0)
                sum = sum + " " + mp->DrawAll();
            else
                sum = sum + mp->DrawAll();
            delete mp;
        }
    }
    else if (s == "ER")
    {
        AbstractGraphic* p1 = new Ellip;
        AbstractGraphic* p2 = new Rect;
        for (int i = 0; i < n; i++)
        {
            pt >> np >> x1 >> y1 >> x2 >> y2;
            AbstractGraphic* A = p1->Clone();
            AbstractGraphic* B = p2->Clone();
            GraphEditor* mp = new GraphEditor(A, B);
            mp->AddGraphic(np, x1, y1, x2, y2);
            if (i > 0)
                sum = sum + " " + mp->DrawAll();
            else
                sum = sum + mp->DrawAll();
            delete mp;
        }
    }
    else if (s == "RL")
    {
        AbstractGraphic* p1 = new Rect;
        AbstractGraphic* p2 = new Line;
        for (int i = 0; i < n; i++)
        {
            pt >> np >> x1 >> y1 >> x2 >> y2;
            AbstractGraphic* A = p1->Clone();
            AbstractGraphic* B = p2->Clone();
            GraphEditor* mp = new GraphEditor(A, B);
            mp->AddGraphic(np, x1, y1, x2, y2);
            if (i > 0)
                sum = sum + " " + mp->DrawAll();
            else
                sum = sum + mp->DrawAll();
            delete mp;
        }
    }
    else if (s == "LR")
    {
        AbstractGraphic* p1 = new Line;
        AbstractGraphic* p2 = new Rect;
        for (int i = 0; i < n; i++)
        {
            pt >> np >> x1 >> y1 >> x2 >> y2;
            AbstractGraphic* A = p1->Clone();
            AbstractGraphic* B = p2->Clone();
            GraphEditor* mp = new GraphEditor(A, B);
            mp->AddGraphic(np, x1, y1, x2, y2);
            if (i > 0)
                sum = sum + " " + mp->DrawAll();
            else
                sum = sum + mp->DrawAll();
            delete mp;
        }
    }
    pt << sum;
}
