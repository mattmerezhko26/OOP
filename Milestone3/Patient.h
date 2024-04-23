/*
Workshop - Milestone#3
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
#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "IOAble.h"
#include "Utils.h"
#include "Ticket.h"
#include "Time.h"

using namespace std;
namespace seneca {
    class Patient : public IOAble {
    private:
        char* m_name;
        int m_OHIP;
        Ticket m_ticket;
        Time m_time;
    protected:
    public:
        Patient() = default;
        Patient(Ticket ticket);
        Patient(const Patient& src);
        Patient& operator=(const Patient& src);
        ~Patient();
        void CopyData(const Patient& src);
        virtual char type() const = 0;
        bool operator==(char c) const;
        bool operator==(const Patient& patient) const;
        void setArrivalTime();
        Time time() const;
        int number() const;
        operator bool() const;
        operator const char* () const;
        ostream& write(ostream& os) const override;
        istream& read(istream& in);
        
    };
}

#endif // !PATIENT_H
