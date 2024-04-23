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
#ifndef PRE_TRIEAGE_H
#define PRE_TRIEAGE_H
#include <iostream>
#include <cstring>
#include "Time.h"
#include "Patient.h"

using namespace std;
namespace seneca {

    const int MAX_LINE = 100;
    class PreTriage {
        Time m_Contaigen; 
        Time m_Triage; 
        Patient* m_patients[MAX_LINE]; 
        char* m_file; 
        int m_totalPatients; 
        Time getWaitTime(const Patient& p) const;
        PreTriage& setAverageWaitTime(const Patient& p);
        int indexOfFirstInLine(const char type);
        PreTriage& load();
        void save();
        void registers();
        void admit();
        void lineup();
    public:
        PreTriage(const char* file);
        ~PreTriage();
        void run();
    };
}

#endif // !PRE_TRIEAGE_H