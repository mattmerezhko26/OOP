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
#include <string>
#include <iomanip>
#include "IOAble.h"
#include "Utils.h"
#include "Ticket.h"
#include "Patient.h"
using namespace std;
namespace seneca {

    Patient::Patient(Ticket ticket) : m_name(nullptr), m_OHIPnum(0), m_ticket(ticket) { }

    Patient& Patient::operator=(const Patient& source)
    {
        if (this != &source) {
            delete[] m_name;
            m_name = nullptr;
            CopyData(source);
        }
        return *this;
    }

    Patient::~Patient()
    {
        delete[] m_name;
        m_name = nullptr;
    }
    Patient::Patient(const Patient& source) : m_ticket(source.m_ticket)
    {
        CopyData(source);
    }

    void Patient::CopyData(const Patient& source) {
        delete[] m_name; // Deallocate existing name if any

        if (source.m_name != nullptr && source.m_name[0] != '\0') {
            m_name = new char[strlen(source.m_name) + 1];
            strcpy(m_name, source.m_name);
        }
        else {
            m_name = nullptr; // Ensure m_name is null if source name is null
        }

        m_OHIPnum = source.m_OHIPnum;
        m_ticket = source.m_ticket;
    }

    bool Patient::operator==(const char character) const
    {
        return type() == character;
    }

    bool Patient::operator==(const Patient& patient) const
    {
        return type() == patient.type();
    }

    void Patient::setArrivalTime()
    {
        m_ticket.resetTime();
    }

    Time Patient::time() const
    {
        return m_ticket.time();
    }

    int Patient::number() const
    {
        return m_ticket.number();
    }

    Patient::operator bool() const {
        return (m_name != nullptr && m_name[0] != '\0') &&
            (m_OHIPnum > 100000000 && m_OHIPnum < 999999999) &&
            (strlen(m_name) <= MAX_CHAR);
    }

    Patient::operator const char* () const
    {
        return m_name;
    }

    ostream& Patient::write(ostream& os) const {
        if (&os == &clog || &os == &cout) {
            if (!*this) {
                os << "Invalid Patient Record";
            }
            else {
                if (&os == &clog) {
                    os << setw(53) << left << setfill('.') << m_name;
                    os << m_OHIPnum;
                    os << setw(5) << right << setfill(' ') << m_ticket.number();
                    os << " ";
                    os << m_ticket.time();
                }
                else {
                    os << m_ticket << endl;
                    os << m_name << ", OHIP: " << m_OHIPnum << endl;
                }
            }
        }
        else {
            os << type() << "," << m_name << "," << m_OHIPnum << ",";
            m_ticket.write(os);
        }
        return os;
    }

    istream& Patient::read(istream& in)
    {
        if (&in == &cin) {
            char local[255] = {};
            string OHIPstr;
            bool isValid = false;

            cout << "Name: ";
            in.ignore(1000000, '\n');
            in.get(local, 255, '\n');
            in.clear();
            delete[] m_name;
            m_name = new char[strlen(local) + 1];
            strcpy(m_name, local);

            cout << "OHIP: ";
            while (!isValid) {
                in >> OHIPstr;
                isValid = U.checkNumber(OHIPstr);
                if (isValid) {
                    m_OHIPnum = stoi(OHIPstr);
                    if (m_OHIPnum < 100000000 || m_OHIPnum > 999999999) {
                        cout << "Invalid value entered, retry [100000000 <= value <= 999999999]: ";
                        isValid = false;
                    }
                }
                else {
                    cout << "Bad integer value, try again: ";
                }
                in.clear();
                in.ignore(1000000, '\n');
            }
            cout << endl;
        }
        else {
            char text[MAX_SIZE + 1];

            in.getline(text, MAX_CHAR, ',');

            char* name = new char[strlen(text) + 1];
            strcpy(name, text);
            checkWordSize(name);
            delete[] name;
            name = nullptr;

            in >> m_OHIPnum;

            in.ignore(MAX_SIZE, ',');
            if (!m_ticket.read(in)) {
                in.setstate(std::ios::failbit);
            }
        }

        return in;
    }

    void Patient::checkWordSize(char*& word) {
        char* newWord = new char[MAX_CHAR + 1];
        strncpy(newWord, word, MAX_CHAR);
        newWord[MAX_CHAR] = '\0';

        delete[] m_name;
        m_name = newWord;
    }

    const char* Patient::getName()
    {
        return m_name;
    }

    int Patient::getOHIP() const
    {
        return m_OHIPnum;
    }

    const Ticket& Patient::getTicket() const
    {
        return m_ticket;
    }

    void Patient::displayLineup(ostream& os) const {
        os << left << setw(53) << setfill('.') << m_name;
        os << right << setw(9) << setfill(' ') << m_OHIPnum;
        os << right << setw(5) << m_ticket.getNumber();
        os << " " << m_ticket.time() << endl;
    }

}