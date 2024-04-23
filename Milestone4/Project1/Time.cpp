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
#include "Time.h"
#include <iostream>
#include <iomanip>
#include "Utils.h"
#include "Time.h"
using namespace std;

namespace seneca {
	Time& Time::reset()
	{
		m_min = U.getTime();
		return *this;
	}
	Time::Time(unsigned int min)
	{
		m_min = min;
	}
	std::ostream& Time::write(std::ostream& ostr) const {
		// Calculate hours and minutes
		int hour = m_min / 60;
		int min = m_min - (hour * 60);

		// Ensure two digits for hours and minutes
		ostr << std::setw(2) << std::setfill('0') << hour << ":"
			<< std::setw(2) << std::setfill('0') << min;

		return ostr;
	}
	std::istream& Time::read(std::istream& istr) {
		char colon;
		int hour = 0, min = 0;

		istr >> hour; // Read hours
		istr >> colon; // Read ':' separator
		istr >> min; // Read minutes

		if (istr && colon == ':') {
			m_min = hour * 60 + min; // Calculate total minutes
		}
		else {
			istr.setstate(std::ios::failbit); // Set failbit if input format is incorrect
		}

		return istr;
	}


	Time::operator unsigned int() const
	{
		return m_min;
	}
	Time& Time::operator*=(int val)
	{
		m_min *= val;
		return *this;
	}
	Time& Time::operator-=(const Time& D) {
		int diff = m_min - D.m_min;
		m_min = (diff >= 0) ? diff : diff + 1440;
		return *this;
	}
	Time Time::operator-(const Time& T) const {
		int diff = m_min - T.m_min;
		int resultMin = (diff >= 0) ? diff : diff + 1440;
		return Time(resultMin);
	}
	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		D.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Time& D)
	{
		D.read(istr);
		return istr;
	}
}
