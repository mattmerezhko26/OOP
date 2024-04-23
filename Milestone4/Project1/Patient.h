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
#ifndef PATIENT_MODULE_H
#define PATIENT_MODULE_H

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

namespace seneca {

	const int MAX_NAME = 50;
	const int MAX_BUFFER = 100;

	class Patient : public IOAble {
		char* m_name;
		int m_OHIP;
		Ticket  m_ticket;
	public:
		Patient(int ticketNumber);
		Patient(const Patient& secondPatient);
		Patient& operator=(const Patient& secondPatient);
		virtual ~Patient();
		virtual char type() const = 0;
		bool operator==(char rhs) const;
		bool operator==(const Patient& secondPatient) const;
		Time time() const;
		int number() const;
		void setArrivalTime();
		operator bool() const;
		operator const char* () const;
		virtual std::ostream& write(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		bool Ninedigits(int OHIP) const;

	};

}

#endif // !PATIENT_MODULE_H
