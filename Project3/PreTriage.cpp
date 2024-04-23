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
#include <cstring>
#include <fstream>
#include <iomanip>

#include "Time.h"
#include "Patient.h"
#include "PreTriage.h"
#include "Utils.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Menu.h"

using namespace std;
namespace seneca {

 
    Time PreTriage::getWaitTime(const Patient& p) const
    {
        Time t = {};
        int total = 0;
        // Count the number of patients of the same type as p
        for (int i = 0; i < m_totalPatients; i++) {
            if (m_patients[i]->type() == p.type()) {
                total++;
            }
        }
        // Calculate wait time based on the type of patient
        if (p.type() == 'C') {
            t = total * m_Contaigen;
        }
        else {
            t = total * m_Triage;
        }

        return t;
    }

    PreTriage& PreTriage::setAverageWaitTime(const Patient& p) {
        Time& current = (p.type() != 'C') ? m_Triage : m_Contaigen; // Set current time based on patient type
        Time CT = Time().reset(); // Current time
        Time PTT = p.time(); // Patient's arrival time
        Time& AWT = current; // Average wait time reference
        int PTN = p.number(); // Patient number
        Time difference = CT - PTT; // Time difference between current time and patient's arrival time
        Time AVGtime = AWT * (PTN - 1); // Total wait time of previous patients
        AWT = (difference + AVGtime) / PTN; // Update average wait time

        return *this;
    }

    int PreTriage::indexOfFirstInLine(const char type)
    {
        int index = -1;

        for (int i = 0; i < m_totalPatients && index == -1; i++) {
            if (*m_patients[i] == type) {
                index = i;
            }
        }

        return index;
    }

    PreTriage& PreTriage::load() {
        cout << "Loading data..." << endl;

        if (m_file) {
            ifstream file(m_file);

            if (file.is_open()) {
                file >> m_Contaigen;
                file.ignore(10000, ',');
                file >> m_Triage;
                file.ignore(10000, '\n');

                char patientType = {}; // Changed variable name to patientType
                for (int i = 0; i < MAX_LINE && file >> patientType; ++i) {
                    file.ignore(10000, ',');

                    if (patientType == 'C') {
                        m_patients[i] = new TestPatient();
                    }
                    else {
                        m_patients[i] = new TriagePatient();
                    }

                    file >> *m_patients[i];
                    ++m_totalPatients;
                }

                if (m_totalPatients == MAX_LINE && file.peek() != EOF) {
                    cout << "Warning: number of records exceeded " << MAX_LINE << endl;
                    file.ignore(10000, '\n');
                    cout << m_totalPatients << " Records imported..." << endl << endl;
                }
                else if (m_totalPatients == 0) {
                    cout << "No data or bad data file!" << endl << endl;
                }
                else {
                    cout << m_totalPatients << " Records imported..." << endl << endl;
                }
            }
            else {
                cerr << "No data or bad data file!" << endl << endl;
            }
        }

        return *this;
    }
    void PreTriage::save()
    {
        cout << "Saving lineup..." << endl;
        ofstream file(m_file);

        if (!file) {
            cerr << "Failed to read patient information!" << m_file << endl;
        }
        else {
        
            file << m_Contaigen << ',' << m_Triage << endl;
            int countC = 0;
            int countT = 0;
            for (int i = 0; i < m_totalPatients; ++i) {
                file << *m_patients[i] << endl;
                if (m_patients[i]->type() == 'C') {
                    ++countC;
                }
                else {
                    ++countT;
                }
            }
            cout << countC << " Contagion Tests and " << countT << " Triage records were saved!" << endl;
        }
        file.close();
    }

    void PreTriage::registers() {
        if (m_totalPatients >= MAX_LINE) {
            cout << "Line up full!" << endl;
            return;
        }

        Menu::showRegistrationMenu();

        string input;
        cin >> input;
        int opt = -1;

        if (U.checkNumber(input)) {
            opt = stoi(input);

            if (opt == 1) {
                m_patients[m_totalPatients] = new TestPatient();
            }
            else if (opt == 2) {
                m_patients[m_totalPatients] = new TriagePatient();
            }
            else if (opt == 0) {
                // Do nothing, user chose to exit
            }
            else {
                cerr << "Invalid selection!" << endl;
                return;
            }

            cout << "Please enter patient information: " << endl;
            cin.clear();
            cin >> *m_patients[m_totalPatients];
            m_patients[m_totalPatients]->setArrivalTime();

            cout << "******************************************" << endl;
            cout << *m_patients[m_totalPatients];
            cout << "Estimated Wait Time: " << getWaitTime(*m_patients[m_totalPatients]) << endl;
            cout << "******************************************" << endl << endl;

            ++m_totalPatients;
        }
        else {
            cerr << "Invalid input! Please enter a number." << endl;
        }
    }

    void PreTriage::admit() {
        Menu::showAdmittanceMenu();

        string input;
        cin >> input;
        int opt = -1;

        if (U.checkNumber(input)) {
            opt = stoi(input);

            char type = {};

            if (opt == 1) {
                type = 'C';
            }
            else if (opt == 2) {
                type = 'T';
            }
            else if (opt == 0) {
                return; // User chose to exit
            }
            else {
                cerr << "Invalid selection!" << endl;
                return;
            }

            int idx = indexOfFirstInLine(type);

            if (idx != -1) {
                cout << endl << "******************************************" << endl;
                cout << "Call time: [" << Time().reset() << "]" << endl;
                cout << "Calling at for ";
                cout << *m_patients[idx];
                cout << "******************************************" << endl << endl;

                setAverageWaitTime(*m_patients[idx]);

                removeDynamicElement(m_patients, idx, m_totalPatients);
            }
            else {
                cout << "Lineup is empty!" << endl;
            }
        }
        else {
            cerr << "Invalid input! Please enter a number." << endl;
        }
    }

    void PreTriage::lineup()
    {
        int opt = -1;
        while (opt != 0) {
            Menu::showLineupMenu();
            string input;
            cin >> input;
            if (U.checkNumber(input)) {
                opt = stoi(input);
            }
            else {
                cerr << "Invalid input! Please enter a number." << endl;
            }
            char type = {};

            if (opt == 1) {
                type = 'C';
            }
            else if (opt == 2) {
                type = 'T';
            }
            else if (opt != 0) {
                cerr << "Invalid selection! Please enter a number between 0 and 2." << endl;
            }

            cout << "Row - Patient name                                          OHIP     Tk #  Time" << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            bool isEmpty = true;
            int count = 0;
            for (int i = 0; i < m_totalPatients; ++i) {
                if (m_patients[i]->type() == type) {
                    cout << left << setw(4) << count + 1 << "- ";
                    m_patients[i]->displayLineup(cout);
                    isEmpty = false;
                    count++;
                }
            }
            if (isEmpty) {
                cout << "Line up is empty!" << endl;
            }
            cout << "-------------------------------------------------------------------------------" << endl;
            opt = 0;
        }
    }

    PreTriage::PreTriage(const char* file) : m_Contaigen(15), m_Triage(5), m_totalPatients(0)
    {
        m_file = new char[strlen(file) + 1];
        strcpy(m_file, file);
        for (int i = 0; i < MAX_LINE; i++) {
            m_patients[i] = nullptr;
        }
        load();
    }

    PreTriage::~PreTriage()
    {
        save();
        for (int i = 0; i < m_totalPatients; i++) {
            delete m_patients[i];
        }
        delete[] m_file;
        m_file = nullptr;
    }

    void PreTriage::run() {
        bool isRunning = true;

        while (isRunning) {
            cout << "General Healthcare Facility Pre-Triage Application" << endl;
            cout << "1- Register" << endl;
            cout << "2- Admit" << endl;
            cout << "3- View Lineup" << endl;
            cout << "0- Exit" << endl;
            cout << "> ";

            string input;
            cin >> input;
            cin.ignore(10000, '\n');
            int opt = -1;

            if (U.checkNumber(input)) {
                opt = stoi(input);

                if (opt >= 0 && opt <= 3) {
                    if (opt == 1) {
                        registers();
                    }
                    else if (opt == 2) {
                        admit();
                    }
                    else if (opt == 3) {
                        lineup();
                    }
                    else if (opt == 0) {
                        isRunning = false;
                    }
                }
                else {
                    cerr << "Invalid selection! Please enter a number between 0 and 3." << endl;
                }
            }
            else {
                cerr << "Invalid input! Please enter a number." << endl;
            }
        }
    }
}