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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "IOAble.h"
#include "Utils.h"
#include "Ticket.h"
#include "Patient.h"

using namespace std;
namespace seneca {
    

    Patient::Patient(Ticket ticket){
        m_name = nullptr;
        m_OHIP = 0;
        m_ticket = ticket; 
        m_time = 0;
    }

    Patient::Patient(const Patient& src)
    {
        m_ticket = src.m_ticket;
        CopyData(src);
    }

    Patient& Patient::operator=(const Patient& src)
    {
        if (this != &src) {
            delete[] m_name;
            m_name = nullptr;
            CopyData(src);
        }
        return *this;
    }

    Patient::~Patient()
    {
        delete[] m_name;
        m_name = nullptr;
    }

    void Patient::CopyData(const Patient& src)
    {
        if (src.m_name != nullptr && src.m_name[0] != '\0') {
            m_name = new char[strlen(src.m_name) + 1];
            strcpy(m_name, src.m_name);
        }

        m_OHIP = src.m_OHIP;
        m_ticket = src.m_ticket;
        m_time = src.m_time;
    }

    bool Patient::operator==(char c) const
    {
        return type() == c;
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

    Patient::operator bool() const
    {
        return (m_name != nullptr && m_name[0] != '\0' && m_OHIP >= 100000000 && m_OHIP <= 999999999 && strlen(m_name) <= MAX_CHAR);
    }

    Patient::operator const char* () const
    {
        return m_name;
    }

    ostream& Patient::write(ostream& os) const
    {
        if (&os == &clog) {
            if (!*this) {
                os << "Invalid Patient Record";
            }
            else {
                os << setw(53) << left << setfill('.') << m_name;
                os << m_OHIP;
                os << setw(5) << right << setfill(' ') << m_ticket.number();
                os << " ";
                os << m_ticket.time();
            }
        }
        else if (&os == &cout) {
            if (!*this) {
                os << "Invalid Patient Record" << endl;
            }
            else {
                os << m_ticket;
                os << endl;
                os << m_name;
                os << ", OHIP: ";
                os << m_OHIP;
                os << endl;
            }
        }
        else {
            os << type() << ",";
            os << m_name << ",";
            os << m_OHIP << ",";
            m_ticket.write(os);
        }

        return os;
    }

    istream& Patient::read(istream& in)
    {
        if (&in == &cin) {
            char local[255];
            string OHIPstr;
            bool isValid = false;

            cout << "Name: ";
            in.get(local, 255);
            in.ignore(1000, '\n');
            delete[] m_name;
            m_name = new char[strlen(local) + 1];
            strcpy(m_name, local);

            cout << "OHIP: ";
            do {
                in >> OHIPstr;
                isValid = U.isValid(OHIPstr);
                if (isValid) {
                    m_OHIP = stoi(OHIPstr);
                    if (m_OHIP < 100000000 || m_OHIP > 999999999) {
                        cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
                        isValid = false;
                    }
                }
                else {
                    cout << "Bad integer value, try again: ";
                }
            } while (!isValid);
        }
        else {
            string line;
            getline(in, line);

            if (!line.empty()) {
                stringstream ss(line);
                char* tk = nullptr;

                tk = strtok(const_cast<char*>(line.c_str()), ",");
                char* name = new char[strlen(tk) + 1];
                strcpy(name, tk);

                // Check if name exceeds MAX_CHAR
                if (strlen(name) > MAX_CHAR) {
                    char* newWord = new char[MAX_CHAR + 1];
                    strncpy(newWord, name, MAX_CHAR);
                    newWord[MAX_CHAR] = '\0';
                    delete[] m_name; // Deallocate previous memory
                    delete[] name;   // Deallocate memory for original name
                    m_name = newWord;
                }
                else {
                    delete[] m_name;
                    m_name = name;
                }

                tk = strtok(nullptr, ",");
                m_OHIP = stoi(tk);

                tk = strtok(nullptr, ",");
                m_ticket = stoi(tk);

                tk = strtok(nullptr, ",");
                Time t;
                std::istringstream timeStream(tk);
                timeStream >> t;
                m_ticket.setTime(t);

                in.seekg(-1, std::ios::cur);
            }
        }

        return in;
    }

    
}