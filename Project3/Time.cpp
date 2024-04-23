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
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include "Time.h"
#include "Utils.h"

using namespace std;
namespace seneca {
    Time::Time(unsigned int minute)
    {
        m_minute = minute;
    }

    Time& Time::reset()
    {
        m_minute = U.getTime();
        return *this;
    }

    ostream& Time::write(ostream& os) const {
        unsigned int hours = m_minute / 60;
        unsigned int minutes = m_minute % 60;

        // Write hours with leading zero if necessary
        if (hours < 10) {
            os << "0";
        }
        os << hours << ":";

        // Write minutes with leading zero if necessary
        if (minutes < 10) {
            os << "0";
        }
        os << minutes;

        return os;
    }

    istream& Time::read(istream& is) {
        char colon;
        unsigned int input_hours, input_minutes;

        is >> input_hours >> colon >> input_minutes;

        if (is && colon == ':' && input_hours < 25 && input_minutes < 60) {
            m_minute = input_hours * 60 + input_minutes;
        }
        else {
            m_minute = 0; // Set to 0 if input is invalid
        }

        return is;
    }

    Time::operator unsigned int() const
    {
        return m_minute;
    }

    Time& Time::operator*=(int val)
    {
        m_minute *= val;
        return *this;
    }

    Time& Time::operator-=(const Time& D) { return m_minute >= D.m_minute ? (m_minute -= D.m_minute, *this) : (m_minute = 1440 - (D.m_minute - m_minute), *this); }

    Time Time::operator-(const Time& T) const { Time r = *this; return r -= T; }

    ostream& operator<<(ostream& os, const Time& T)
    {
        T.write(os);
        return os;
    }

    istream& operator>>(istream& is, Time& T)
    {
        T.read(is);
        return is;
    }
}