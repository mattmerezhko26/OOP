/***********************************************************************
// OOP244 Project
//
// File  Utils.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
/*
Workshop - Milestone#3
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
   
   void Utils::error()
   {
       cout << "Bad time entry, retry (HH:MM): ";
   }
   bool Utils::isNumber(int value) {
       if (std::cin.fail()) {
           std::cin.clear();
           std::cin.ignore(10000, '\n');
           return false;
       }

       return true;
   }
   bool Utils::Char(const char* word)
   {
       if (word == nullptr || word[0] == '\0') {
           return false;
       }

       return (strlen(word) <= MAX_CHAR);
   }

   bool Utils::isValid(const std::string& str)
   {
       if (str.empty()) {
           return false;
       }

       for (char ch : str) {
           if (!isdigit(ch)) {
               return false;
           }
       }

       return true;
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
   void Utils::setDebugTime(int hour, int min) {
      seneca::debug = true;
      m_testMins = hour * 60 + min;
   }

   int Utils::strcmp(const char* s1, const char* s2)const {
      int i;
      for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      return s1[i] - s2[i];
   }
   // end provided code
}