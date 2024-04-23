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
#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "IOAble.h"
#include "Utils.h"
#include "Ticket.h"

using namespace std;
namespace seneca {

    const int MAX_SIZE = 512;
    const int MAX_CHAR = 50;

    class Patient : public IOAble {
    private:
        char* m_name;
        int m_OHIPnum;
        Ticket m_ticket;
    protected:
    public:
        Patient() = default;
        Patient(Ticket ticket);
        Patient(const Patient& source);
        Patient& operator=(const Patient& source);
        ~Patient();
        void CopyData(const Patient& source);
        virtual char type() const = 0;
        bool operator==(const char character) const;
        bool operator==(const Patient& patient) const;
        void setArrivalTime();
        Time time() const;
        int number() const;
        operator bool() const;
        operator const char* () const;
        ostream& write(ostream& os) const override;
        istream& read(istream& in);
        void checkWordSize(char*& word);
        const char* getName();
        int getOHIP() const;
        const Ticket& getTicket() const;
        virtual void displayLineup(ostream& os) const;
    };
}

#endif // !PATIENT_H
