#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <iostream>
#include <set>

#include "IObserver.h"

class Observable
{
    public:
        Observable();
        virtual ~Observable();
        void notify(std::string data) const;
        void addObserver(IObserver* observer);
        void removeObserver(IObserver* observer);
    private:
        std::set<IObserver*> list_observers;
};

#endif // OBSERVABLE_H
