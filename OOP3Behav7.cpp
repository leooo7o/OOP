#include "pt4.h"
using namespace std;

class Iterator
{
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual int CurrentItem() = 0;
};
class ConcreteIteratorA :public Iterator {
private:

};
class ConcreteIteratorB :public Iterator {
private:

};
class ConcreteIteratorC :public Iterator {
private:

};
class Aggregate
{
public:
    virtual Iterator* CreateIterator() = 0;
};
class ConcreteAggregateA :public Aggregate {
private:
    int size
};
class ConcreteAggregateB :public Aggregate {

};
class ConcreteAggregateC :public Aggregate {

};
// Implement the ConcreteAggregateA, ConcreteAggregateB
//   and ConcreteAggregateC descendant classes

// Implement the ConcreteIteratorA, ConcreteIteratorB
//   and ConcreteIteratorC descendant classes

void Solve()
{
    Task("OOP3Behav7");

}
