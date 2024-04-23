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
#include <iomanip>
#include "TriagePatient.h"

int seneca::TriagePatient::nextTriageTicket = 1;

using namespace std;
namespace seneca {
    TriagePatient::TriagePatient() : Patient(nextTriageTicket++)
    {
        m_sympt = nullptr;
    }

    char TriagePatient::type() const
    {
        return 'T';
    }

    TriagePatient::~TriagePatient()
    {
        delete[] m_sympt;
        m_sympt = nullptr;
    }

    ostream& TriagePatient::write(ostream& os) const
    {
        if (&os == &cout) {
            os << "TRIAGE" << endl;
            Patient::write(os);
            os << "Symptoms: " << m_sympt << endl;
        }
        else if (&os == &clog) {
            Patient::write(os);
        }
        else {
            Patient::write(os);
            os << "," << m_sympt;
        }

        return os;
    }

    istream& TriagePatient::read(istream& is) {
        char str[512];
        delete[] m_sympt;
        Patient::read(is);
        if (&is != &cin) {
            is.ignore(MAX_SIZE, ',');
            is.getline(str, 511, '\n');
            nextTriageTicket = Patient::number() + 1;
        }
        else {
            cout << "Symptoms: ";
            cin.get(str, 512);
            is.ignore(1000000, '\n');
            nextTriageTicket = 0;
        }
        m_sympt = new char[strlen(str) + 1];
        strcpy(m_sympt, str);
        is.clear();
        if (is.fail()) {
            delete[] m_sympt;
            m_sympt = nullptr;
        }
        return is;
    }
}