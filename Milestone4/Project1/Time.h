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
#ifndef TIME_MODULE_H
#define TIME_MODULE_H
#include <iostream>
namespace seneca {
	class Time {
		unsigned int m_min;
	public:
		Time& reset();
		Time(unsigned int min = 0u);
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		operator unsigned int()const;
		Time& operator*= (int val);
		Time& operator-= (const Time& D);
		Time operator-(const Time& T)const;
	};

	std::ostream& operator<<(std::ostream& ostr, const Time& D);
	std::istream& operator>>(std::istream& istr, Time& D);
}

#endif
