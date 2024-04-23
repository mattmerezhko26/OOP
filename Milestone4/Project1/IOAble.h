/*
Workshop - Milestone#4
Full Name : Matvii Merezhko
Student ID# : 127769230
Email :mmerezhko@myseneca.ca
Section :ZGG

    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
*/
/////////////////////////////////////////////////////////////////////////*/
#ifndef IOAble_H
#define IOAble_H
#include <iostream>
#include <iomanip>

namespace seneca {
    class IOAble {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual ~IOAble();
    };

    std::ostream& operator<<(std::ostream& os, const IOAble& obj);
    std::istream& operator>>(std::istream& is, IOAble& obj);
}
#endif // !IOAble_H