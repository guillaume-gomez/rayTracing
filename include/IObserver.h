#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <iostream>

class IObserver
{
    public:
        virtual void update(std::string data) = 0;
};

#endif // IOBSERVER_H
