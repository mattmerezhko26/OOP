/*
Workshop - Milestone#1
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
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include "Time.h"
#include "Utils.h"

using namespace std;
namespace seneca {
	Time::Time(unsigned int min ) {
		m_min = min;
	
	}
	Time& Time::reset() {
		m_min = U.getTime();
		return *this;
		
	}
	void Time::write(ostream& output)const {
		
		output << setw(2) << setfill('0') << m_min / 60 << ":" //Hours
			<< setw(2) << setfill('0') << m_min % 60; // Minutes
	}
	void Time::read(istream& input) {
    
		char c;
		input >> m_min;//Reading hours
		if (!input.fail()) {
			input >> c;
			if (c != ':') {//Checking for colon
				input.setstate(ios::failbit); //Setting the failure state if colon missing
				return;
			}
			input >> m_min;// Reading minutes
		}
	}
	Time::operator unsigned int()const {
		
		return m_min;
	}
	Time& Time::operator*= (int val) {
		
		m_min *= val;
		return *this;
	}
	Time& Time::operator-= (const Time& D) {
		
		int diff;
		diff = m_min - D.m_min;
		if (diff < 0) {
			diff += 1440;
		}
		m_min = diff;
		return *this;
	}
	Time Time::operator-(const Time& T)const {
		
		int diff;
		diff = m_min - T.m_min;
		if (diff < 0) {
			diff += 1440;
		}
		
		return Time(diff);
	}
	ostream& operator<<(ostream& output, const Time& T) {
		
		T.write(output);
		return output;
	}
	istream& operator>>(istream& input, Time& T) {
		char input1[10];
		bool isValid = false;

		do {
			input >> input1;

			char* hour = strtok(input1, ":");
			char* minute = strtok(nullptr, ":");

			if (hour == nullptr || minute == nullptr || !U.isNumber(std::stoi(hour)) || !U.isNumber(std::stoi(minute))) {
				U.error();
			}
			else {
				unsigned int h = std::stoi(hour);
				unsigned int m = std::stoi(minute);
				T.m_min = h * 60 + m;
				isValid = true;
			}
		} while (!isValid); 

		return input;
	}

}