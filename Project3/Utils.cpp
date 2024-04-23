/*/////////////////////////////////////////////////////////////////////////
MILESTONE - #5
Full Name  : Matvii Merezhko
Student ID#: 127769230
Email      : mmerezhko@myseneca.ca
Section    : ZGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <algorithm>
#include "Utils.h"
#include "Time.h"
using namespace std;
namespace seneca {
    // start provided code
    bool debug = false;
    Utils U;
    int Utils::getTime() {
        int mins = -1;
        if (debug) {
            int duration[]{ 3,5,9,20,30 };
            mins = (m_testMins %= 1440);
            m_testMins += duration[m_testIndex++ % 5];
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    void Utils::setDebugTime(int hour, int min) {
        seneca::debug = true;
        m_testMins = hour * 60 + min;
    }

    int Utils::strcmp(const char* s1, const char* s2)const {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }

    bool Utils::isNumber(int value)
    {
        bool isTrue = false;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else {
            isTrue = true;
        }

        return isTrue;
    }

    void Utils::error()
    {
        cout << "Bad time entry, retry (HH:MM): ";
    }

    bool Utils::maxChar(const char* word) {
        if (word != nullptr && word[0] != '\0') {
            size_t count = strlen(word);
            if (count <= 50) {
                return true;
            }
        }
        return false;
    }

    bool Utils::checkNumber(const std::string& str)
    {
        return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
    }

    void Utils::copy(char*& dest, const char* src)
    {
        delete[] dest;
        dest = nullptr;
        if (src != nullptr && src[0] != '\0') {
            dest = new char[strlen(src) + 1];
            strcpy(dest, src);
        }
    }
    // end provided code
}