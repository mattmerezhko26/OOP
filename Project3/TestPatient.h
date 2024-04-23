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
#ifndef TEST_PATIENT_H
#define TEST_PATIENT_H

#include <iostream>
#include <cstring>

#include "Patient.h"

namespace seneca {

    class TestPatient : public Patient {
    private:
        static int nextTestTicket;
    public:
        TestPatient();
        char type() const override;
        virtual ostream& write(ostream& os) const override;
        virtual istream& read(istream& is) override;
    };
}

#endif // !TEST_PATIENT_H
