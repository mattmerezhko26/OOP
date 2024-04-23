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
#ifndef TESTPATIENT_MODULE_H
#define TESTPATIENT_MODULE_H

#include <iostream>
#include "Patient.h"

namespace seneca {

	class TestPatient :public Patient {
		static int m_nextTestTicket;
	public:
		TestPatient();
		char type() const;
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		~TestPatient() = default;
	};

}

#endif 