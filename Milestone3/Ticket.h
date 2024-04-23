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
#ifndef SENECA_TICKET_H_
#define SENECA_TICKET_H_
#include <iostream>
#include "Time.h"
#include "IOAble.h"
namespace seneca {
   class Ticket:public IOAble{
      Time m_time;
      int m_number;
   public:
      Ticket() = default;
      Ticket(int number);
      Time time()const;
      int number()const;
      void resetTime();
      void setTime(const Time& time);
      std::ostream& write(std::ostream& ostr )const;
      std::istream& read(std::istream& istr);
   };
}
#endif // !SENECA_TICKET_H_
