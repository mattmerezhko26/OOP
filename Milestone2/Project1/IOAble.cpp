/*
Workshop - Milestone#2
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
#include "IOAble.h"
#include <iomanip>
#include <string>

using namespace std;

namespace seneca {
    ostream& operator<<(ostream& os, const IOAble& obj) {
        return obj.write(os);
    }

    istream& operator>>(istream& is, IOAble& obj) {
        return obj.read(is);
    }

    IOAble::~IOAble() {
        
    }
}
