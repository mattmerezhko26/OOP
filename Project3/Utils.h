#pragma once
#ifndef SENECA_UTILS_H_
#define SENECA_UTILS_H_
#include <iostream>
#include <iomanip>

using namespace std;
namespace seneca {
    class Utils {
        unsigned int m_testMins = 480;
        unsigned int m_testIndex = 0;
    public:
        void setDebugTime(int hour, int min);
        int getTime();
        int strcmp(const char* s1, const char* s2)const;

        bool isNumber(int value);
        void error();
        bool maxChar(const char* word);
        bool checkNumber(const std::string& str);
        void copy(char*& dest, const char* src);
    };

    extern bool debug;
    extern Utils U;
    template <typename type>
    void removeDynamicElement(type* array[], int index, int& size) {
        delete array[index];
        for (int j = index; j < size; j++) {
            array[j] = array[j + 1];
        }
        size--;
    }
}
#endif // !SENECA_UTILS_H_