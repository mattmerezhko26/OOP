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