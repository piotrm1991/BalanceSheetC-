#include <iostream>
#pragma once

using namespace std;

class Amount{
public:
    void changeCommaToDot(string &amount);
    bool checkAmountDigit(string amount);
    bool checkAmountValue(double amount);
};
