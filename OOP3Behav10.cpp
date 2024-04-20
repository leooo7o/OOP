#include "pt4.h"
using namespace std;
class State
{
public:
    virtual string GetNextToken() = 0;
};
class Context
{
    string text;
    State* currentState;
public:
    Context(string s);
    char GetCharAt(int index) { return text[index]; }
    void SetState(State* newState) { currentState = newState; }
    string GetNextToken() {
        return currentState->GetNextToken();
    }
};
class  ConcreteStateNormal :public State {
private:
    Context* ct;
    int index;
public:
    ConcreteStateNormal(int x, Context* p) { index = x; ct = p; }
    string GetNextToken();
};
class  ConcreteStateString :public State {
private:
    Context* ct;
    int index;
public:
    ConcreteStateString(int x, Context* p) { index = x; ct = p; }
    string GetNextToken();
};
class  ConcreteStateComm :public State {
private:
    Context* ct;
    int index;
public:
    ConcreteStateComm(int x, Context* p) { index = x; ct = p; }
    string GetNextToken();
};
class  ConcreteStateFin :public State {
public:
    string GetNextToken() { string s = "err"; return s; }
};
Context::Context(string s) {
    text = s;
    currentState = new ConcreteStateNormal(0,this);
}
string ConcreteStateNormal::GetNextToken() {
        string s = "";
        char c;
        for (int i = index;; i++) {
            c = ct->GetCharAt(i);
            if (c == '.') { return s; ct->SetState(new ConcreteStateFin); ct->SetState(new ConcreteStateFin); }
            if (c == '\"')
            {
                s = "Normal:" + s;
                ct->SetState(new ConcreteStateString(i + 1, ct));
                return s;
            }
            if (c == '{')
            {
                s = "Normal:" + s;
                ct->SetState(new ConcreteStateComm(i + 1, ct));
                return s;
            }
            else
            {
                s+=c;
            }
        }
}
string ConcreteStateString::GetNextToken() {
        string s = "";
        char c;
        for (int i = index;; i++) {
            c = ct->GetCharAt(i);
            if (c == '.') { s = "ErrString:" + s; ct->SetState(new ConcreteStateFin); return s; }
            if (c == '\"') {
                if (ct->GetCharAt(i + 1) == '\"')
                {
                    s += "\"";
                    i++;
                }
                else {
                    s = "String:" + s;
                    ct->SetState(new ConcreteStateNormal(i + 1, ct));
                    return s;
                }
            }
            else
            {
                s.push_back(c);
            }
        }
}
string ConcreteStateComm::GetNextToken() {
    string s = "";
    char c;
    for (int i = index;; i++) {
        c = ct->GetCharAt(i);
        if (c == '.') { s = "ErrComm:" + s; ct->SetState(new ConcreteStateFin); return s; }
        if (c == '}') {
            s = "Comm:" + s;
            ct->SetState(new ConcreteStateNormal(i + 1, ct));
            return s;
        }
        else
        {
            s.push_back(c);
        }
    }
}
void Solve()
{
    Task("OOP3Behav10");
    string s;
    pt >> s;
    Context* A = new Context(s);
    string text;
    text = A->GetNextToken();
    //pt << text;
    while (text!="err") {
        pt <<text;
        text = A->GetNextToken();
    }
}
