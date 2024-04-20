#include "pt4.h"
using namespace std;

class Animal
{
public:
    virtual string GetInfo() = 0;
};
class Cobra :public Animal {
public:
    virtual string GetInfo();
};
string Cobra::GetInfo() {
    string s = "Cobra";
    return s;
}
class Python :public Animal {
public:
    virtual string GetInfo();
};
string Python::GetInfo() {
    string s = "Python";
    return s;
}
class Anaconda :public Animal {
public:
    virtual string GetInfo();
};
string Anaconda::GetInfo() {
    string s = "Anaconda";
    return s;
}
class Gorilla :public Animal {
public:
    virtual string GetInfo();
};
string Gorilla::GetInfo() {
    string s = "Gorilla";
    return s;
}
class Orangutan :public Animal {
public:
    virtual string GetInfo();
};
string Orangutan::GetInfo() {
    string s = "Orangutan";
    return s;
}
class Chimpanzee :public Animal {
public:
    virtual string GetInfo();
};
string Chimpanzee::GetInfo() {
    string s = "Chimpanzee";
    return s;
}
// Implement the Cobra, Python, Anaconda, Gorilla,
//   Orangutan and Chimpanzee descendant classes

class AnimalCreator
{
protected:
    virtual Animal* CreateAnimal(int n) = 0;
public:
    vector<Animal*> GetZoo(vector<int> id);
};

vector<Animal*> AnimalCreator::GetZoo(vector<int> id)
{
    vector<Animal*> zoo;
    for (auto e : id)
        zoo.push_back(CreateAnimal(e));
    return zoo;
}
class SnakeCreator :public AnimalCreator {
    virtual Animal* CreateAnimal(int n);
};
Animal* SnakeCreator::CreateAnimal(int n) {
    if (n == 1) {
        Animal *a1=new Cobra;
        return a1;
    }
    if (n == 2) {
        Animal *a2=new Python;
        return a2;
    }
    else {
        Animal *a3=new Anaconda;
        return a3;
    }
}
class ApeCreator:public AnimalCreator {
    virtual Animal* CreateAnimal(int n);
};
Animal* ApeCreator::CreateAnimal(int n) {
    if (n == 1) {
        Animal *a1=new Gorilla;
        return a1;
    }
    if (n == 2) {
        Animal *a2=new Orangutan;
        return a2;
    }
    else {
        Animal *a3=new Chimpanzee;
        return a3;
    }
}
// Implement the SnakeCreator and ApeCreator descendant classes

void Solve()
{
    Task("OOP1Creat3");
    vector<int> V;
    vector<Animal*> V1,V2;
    for (int i = 0; i < 5; i++)
    {
        int a;
        pt >> a;
        V.push_back(a);
    }
    Show(V.begin(),V.end());
    SnakeCreator e1;
    ApeCreator e2;
    V1=e1.GetZoo(V);
    V2=e2.GetZoo(V);
    for (int i = 0; i < V1.size(); i++)
    {
        pt<<V1[i]->GetInfo();
    }
    for (int i = 0; i < V2.size(); i++)
    {
        pt << V2[i]->GetInfo();
    }
    //Cobra* e3=new Cobra;
   // string s = e3->GetInfo();
    //Show(s);
}
