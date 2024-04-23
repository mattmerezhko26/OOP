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
#define _CRT_SECURE_NO_WARNINGS

#ifndef TIME_H
#define TIME_H

#include <cstdlib>
#include <ctime>

#include "Utils.h"

using namespace std;
namespace seneca {
    class Time {
        unsigned int m_minute;
    public:
        Time(unsigned int minute = 0u);
        Time& reset();
        ostream& write(ostream& os) const;
        istream& read(istream& is);
        operator unsigned int() const;
        Time& operator*=(int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& T) const;
    };
    ostream& operator<<(ostream& os, const Time& T);
    istream& operator>>(istream& is, Time& T);
}

#endif // !TIME_H