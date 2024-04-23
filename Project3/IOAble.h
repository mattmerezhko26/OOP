/*/////////////////////////////////////////////////////////////////////////
MILESTONE - #5
Full Name  : Matvii Merezhko
Student ID#: 127769230
Email      : mmerezhko@myseneca.ca
Section    : ZGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef IOABLE_H
#define IOABLE_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

namespace seneca {
    class IOAble {
    public:
        virtual ostream& write(ostream& os) const = 0;
        virtual istream& read(istream& is) = 0;
        virtual ~IOAble();
    };
    ostream& operator<<(ostream& os, const IOAble& obj);
    istream& operator>>(istream& is, IOAble& obj);
}

#endif // !IOABLE_H
