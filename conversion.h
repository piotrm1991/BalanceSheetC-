#include <iostream>
#pragma once

using namespace std;

class Conversion{
public:
    string intToString (int number);
    int stringToInt(string word);
    double stringToDouble(string amountString);
    string doubleToString(double amountDouble);
};
