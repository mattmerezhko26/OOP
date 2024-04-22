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
#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;
namespace seneca {
	class Menu {
	private:
		char* m_menu;
		int m_numOfOpt;
		int m_numOfTabs;
	public:
		Menu() = default; // default constructor
		Menu(const char* menuContent, int numberOfTabs = 0);//parameterized constructor
		Menu(const Menu& source); // copy constructor
		Menu& operator=(const Menu& source);//copy asssignment operator
		~Menu();//destructor
		void CopyData(const Menu& source);
		void display() const;
		int getOption() const;
		int getTabs() const;
		int& operator>>(int& Selection);
	};
}
#endif // !MENU_H

