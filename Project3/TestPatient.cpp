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
#include <iostream>
#include <cstring>
#include "TestPatient.h"

int seneca::TestPatient::nextTestTicket = 1;

using namespace std;
namespace seneca {
    TestPatient::TestPatient() : Patient(nextTestTicket++) { }

    char TestPatient::type() const
    {
        return 'C';
    }
    ostream& TestPatient::write(ostream& os) const
    {
        if (&os == &cout) {
            os << "Contagion TEST" << endl;
        }
        Patient::write(os);
        return os;
    }

    istream& TestPatient::read(istream& is)
    {
        Patient::read(is);
        if (&is != &cin) {
            nextTestTicket = number() + 1;
        }
        return is;
    }
}