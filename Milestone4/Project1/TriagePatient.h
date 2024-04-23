#ifndef TRIAGE_PATIENT_MODULE_H
#define TRIAGE_PATIENT_MODULE_H

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
#include <iostream>
#include "Patient.h"

namespace seneca {

	const int max_symptom_length = 511;

	class TriagePatient :public Patient {
		static int m_TriageTicket;
		char* m_sympt;
	public:
		TriagePatient();
		char type() const;
		TriagePatient(const TriagePatient& src);
		TriagePatient& operator=(const TriagePatient& src);
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		virtual ~TriagePatient();
	};

}

#endif // !TESTPATIENT_MODULE_H

