#include "Observable.h"

Observable::Observable()
{
    //ctor
}

Observable::~Observable()
{
    //dtor
}

void Observable::notify(std::string data) const
{
    // Notifier tous les observers
    for (std::set<IObserver*>::const_iterator it = list_observers.begin(); it != list_observers.end(); ++it) {
        (*it)->update(data);
    }
}

void Observable::addObserver(IObserver* observer)
{
    list_observers.insert(observer);
}

void Observable::removeObserver(IObserver* observer)
{
    list_observers.erase(observer);
}
