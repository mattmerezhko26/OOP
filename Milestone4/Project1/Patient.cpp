/*
Workshop - Milestone#4
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
#include <cstring>
#include <string>
#include <iomanip>
#include "Ticket.h"
#include "Patient.h"
using namespace std;

namespace seneca {

	Patient::Patient(int ticketNumber) : m_ticket(ticketNumber)
	{
		m_name = nullptr;
		m_OHIP = 0;
	}
	Patient::Patient(const Patient& src) : m_ticket(src.m_ticket)
	{
		m_name = nullptr;
		*this = src;
	}
	Patient& Patient::operator=(const Patient& src)
{
    if (this != &src) {
        delete[] m_name;
        m_name = nullptr;
        if (src.m_name != nullptr) {
            m_name = new char[strlen(src.m_name) + 1];
            strcpy(m_name, src.m_name);
        }
        m_OHIP = src.m_OHIP;
        m_ticket = src.m_ticket;
    }
    return *this;
}

	Patient::~Patient()
	{
		delete[] m_name;
	}

	bool Patient::operator==(char rhs) const
	{
		return type() == rhs;

	}

	bool Patient::operator==(const Patient& secondPatient) const
	{
		return type() == secondPatient.type();
	}

	Time Patient::time() const
	{
		return m_ticket.time();
	}

	int Patient::number() const
	{
		return m_ticket.number();
	}

	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}

	bool Patient::Ninedigits(int OHIP) const
	{
		string number = to_string(OHIP);
		return number.length() == 9;
	}

	Patient::operator bool() const
	{
		return m_name != nullptr && m_OHIP != 0 && Ninedigits(m_OHIP);
	}

	Patient::operator const char* () const
	{
		return m_name;
	}

	std::ostream& Patient::write(std::ostream& ostr) const
	{
		if (&ostr == &cout)
		{
			if (!*this)
			{
				ostr << "Invalid Patient Record" << endl;

			}
			else
			{
				m_ticket.write(ostr)
					<< endl;
				ostr << m_name
					<< ", OHIP: "
					<< m_OHIP
					<< endl;

			}
		}
		else if (&ostr == &clog)
		{
			if (!*this)
			{
				ostr << "Invalid Patient Record";

			}
			else
			{
				ostr << left << setw(53) << setfill('.') << m_name << right << m_OHIP << setw(5) << setfill(' ') << m_ticket;
			}
		}
		else {
			ostr << type();
			ostr << ',' << m_name << ',' << m_OHIP << ',';
			m_ticket.write(ostr);

		}
		return ostr;
	}


	std::istream& Patient::read(std::istream& istr)
	{

		if (&istr == &std::cin)
		{
			char temp[MAX_NAME + 1];
			cout << "Name: ";
			istr.get(temp, MAX_NAME, '\n');
			istr.ignore(MAX_BUFFER, '\n');
			delete[] m_name;
			m_name = new char[strlen(temp) + 1];
			strcpy(m_name, temp);
			cout << "OHIP: ";
			istr >> m_OHIP;
			while (istr.fail())
			{
				istr.clear();
				istr.ignore(MAX_BUFFER, '\n');
				cout << "Bad integer value, try again: ";
				istr >> m_OHIP;
				istr.ignore(MAX_BUFFER);
			}
			while (m_OHIP < 100000000 || m_OHIP > 999999999)
			{
				cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
				istr >> m_OHIP;
			}
			istr.ignore(MAX_BUFFER, '\n');
		}
		else
		{
			char temp[MAX_NAME + 1];
			istr.getline(temp, MAX_NAME, ',');
			delete[] m_name;
			m_name = new char[strlen(temp) + 1];
			strcpy(m_name, temp);
			istr >> m_OHIP;
			istr.ignore(MAX_BUFFER, ',');
			if (!m_ticket.read(istr)) {
				istr.setstate(std::ios::failbit);
			}

		}
		return istr;
	}

}