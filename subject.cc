#include "subject.h"
#include "observer.h"

using namespace std;

void Subject::attach(Observer *o)
{
    observers.push_back(o);
};

void Subject::detach(Observer *o)
{
    for (vector<Observer *>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        if (*it == o)
        {
            observers.erase(it);
        }
    }
};

void Subject::notifyObservers(string type, int i1, int i2)
{
    for (auto o : observers)
    {
        o->notify(type, i1, i2);
    }
};
