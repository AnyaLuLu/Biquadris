#include "subject.h"
#include "observer.h"

//copied from ethan chan's a4. will have the change this a bit before submission

void Subject::attach(Observer *o)
{
    observers.push_back(o);
};

void Subject::detach(Observer *o)
{
    for (std::vector<Observer *>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        if (*it == o)
        {
            observers.erase(it);
        }
    }
};

void Subject::notifyObservers()
{
    for (auto o : observers)
    {
        o->notify();
    }
};
