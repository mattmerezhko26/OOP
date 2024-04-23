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
#include <string.h>
#include <cstring>
#include "TriagePatient.h"
using namespace std;

namespace seneca {
	int TriagePatient::m_TriageTicket = 1;

	TriagePatient::TriagePatient() : Patient(m_TriageTicket++)
	{
		m_sympt = nullptr;
	}
	char TriagePatient::type() const
	{
		return 'T';
	}

	TriagePatient::TriagePatient(const TriagePatient& src) : Patient(src)
	{
		m_sympt = nullptr;
		*this = src;
	}

	TriagePatient& TriagePatient::operator=(const TriagePatient& src)
	{

		if (this != &src)
		{

			Patient::operator=(src);

			delete[] m_sympt;
			if (src.m_sympt != nullptr && src.m_sympt[0] != '\0')
			{
				m_sympt = new char[strlen(src.m_sympt) + 1];
				strcpy(m_sympt, src.m_sympt);
			}
		}
		return *this;
	}

	std::ostream& TriagePatient::write(std::ostream& ostr) const
	{
		if (&ostr == &cout) {
			ostr << "TRIAGE" << endl;
			Patient::write(ostr);
			ostr << "Symptoms: "
				<< m_sympt << endl;
		}
		else if (&ostr == &clog) {
			Patient::write(ostr);
		}
		else {
			Patient::write(ostr);
			ostr << ","
				<< m_sympt;
		}
		return ostr;
	}
	std::istream& TriagePatient::read(std::istream& istr) {
		// Define temp variable
		char temp[max_symptom_length];

		delete[] m_sympt;
		m_sympt = nullptr;

		Patient::read(istr);

		// Check if the input stream is not cin
		if (&istr != &cin) {
			// Read symptoms from comma-separated data
			istr.ignore(MAX_BUFFER, ',');
			istr.getline(temp, max_symptom_length, '\n');
			istr.ignore(MAX_BUFFER, '\n');
			m_sympt = new char[strlen(temp) + 1];
			strcpy(m_sympt, temp);
			m_TriageTicket = number() + 1;
		}
		else if (istr.fail()) {
			// Handle failure to read
			delete[] m_sympt;
			m_sympt = nullptr;
		}
		else {
			// Read symptoms from standard input
			cout << "Symptoms: ";
			istr.get(temp, max_symptom_length, '\n');
			m_sympt = new char[strlen(temp) + 1];
			strcpy(m_sympt, temp);
			istr.ignore(MAX_BUFFER, '\n');
		}

		return istr;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_sympt;
	}
}