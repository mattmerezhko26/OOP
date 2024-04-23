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
#include "TestPatient.h"
using namespace std;

namespace seneca {

	int TestPatient::m_nextTestTicket = 1;

	TestPatient::TestPatient() : Patient(m_nextTestTicket++) {

	}
	char TestPatient::type() const
	{
		return 'C';
	}

	std::ostream& TestPatient::write(std::ostream& ostr) const
	{
		if (&ostr == &cout) {
			ostr << "Contagion TEST" << endl;
		}
		Patient::write(ostr);
		return ostr;
	}

	std::istream& TestPatient::read(std::istream& istr)
	{
		Patient::read(istr);

		if (&istr != &cin) {
			m_nextTestTicket = number() + 1;
		}
		return istr;
	}


}