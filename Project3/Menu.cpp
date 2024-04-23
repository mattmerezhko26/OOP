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

#include "Menu.h"

using namespace std;
namespace seneca {
    void Menu::showRegistrationMenu()
    {
        cout << "   Select Type of Registration:" << endl;
        cout << "   1- Contagion Test" << endl;
        cout << "   2- Triage" << endl;
        cout << "   0- Exit" << endl;
        cout << "   > ";
    }

    void Menu::showAdmittanceMenu()
    {
        cout << "   Select Type of Admittance:" << endl;
        cout << "   1- Contagion Test" << endl;
        cout << "   2- Triage" << endl;
        cout << "   0- Exit" << endl;
        cout << "   > ";
    }

    void Menu::showLineupMenu()
    {
        cout << "   Select The Lineup:" << endl;
        cout << "   1- Contagion Test" << endl;
        cout << "   2- Triage" << endl;
        cout << "   0- Exit" << endl;
        cout << "   > ";
    }
}