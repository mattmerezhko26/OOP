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
#include "Menu.h"
#include "Time.h"
#include "Utils.h"
#include <cstring>

using namespace std;
namespace seneca {
    Menu::Menu(const char* menuContent, int numberOfTabs)
    {
        m_menu = nullptr;
        m_numOfOpt = 0;
        m_numOfTabs = numberOfTabs;

        if (menuContent != nullptr) {
            int length = strlen(menuContent);
            m_menu = new char[length + 1];
            strcpy(m_menu, menuContent);

            m_numOfOpt = 1;

           
            for (int i = 0; i < length; i++) {
                if (menuContent[i] == '\n') {
                    m_numOfOpt++;
                }
            }
        }
    }
    Menu::Menu(const Menu& source)
    {
        CopyData(source);
    }

    Menu& Menu::operator=(const Menu& source)
    {
        if (this != &source) {
            delete[] m_menu;
            CopyData(source);
        }
        return *this;
    }

    Menu::~Menu()
    {
        delete[] m_menu;
        m_menu = nullptr;
    }

    void Menu::CopyData(const Menu& source)
    {
        if (source.m_menu != nullptr) {
            m_menu = new char[strlen(source.m_menu) + 1];
            strcpy(m_menu, source.m_menu);
        }
        else {
            m_menu = nullptr;
        }
        m_numOfOpt = source.m_numOfOpt;
        m_numOfTabs = source.m_numOfTabs;
    }

    void Menu::display() const
    {
        for (auto i = 0; i < m_numOfTabs; ++i) {
            cout << "   ";
        }
        for (auto c = m_menu; *c != '\0'; ++c) {
            cout << *c;
            if (*c == '\n') {
                for (auto j = 0; j < m_numOfTabs; ++j) {
                    cout << "   ";
                }
            }
        }
        cout << "\n";
        for (auto i = 0; i < m_numOfTabs; ++i) {
            cout << "   ";
        }
        cout << "0- Exit\n";
        for (auto i = 0; i < m_numOfTabs; ++i) {
            cout << "   ";
        }
        cout << "> ";
    }


    int Menu::getOption() const
    {
        return m_numOfOpt;
    }

    int Menu::getTabs() const
    {
        return m_numOfTabs;
    }

    int& Menu::operator>>(int& Selection) {
            bool isValid = false;
            char nextChar;
            display();
            while (isValid != true) {
                cin >> Selection;
                nextChar = cin.get(); 
                if (!U.isNumber(Selection)) {
                    cout << "Bad integer value, try again: ";
                }
                else if (nextChar != '\n') {
                    cout << "Only enter an integer, try again: ";
                    cin.ignore(10000, '\n');
                }
                else if (Selection < 0 || Selection > getOption() - 1) {
                    cout << "Invalid value enterd, retry[0 <= value <= " << getOption() - 1 << "]: ";
                }
                else {
                    isValid = true;
                }
            }

            return Selection;
    }
    

}