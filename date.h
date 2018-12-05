#include <iostream>
#include "presentDate.h"
#include "conversion.h"
#pragma once

using namespace std;

class Date{
public:
    bool checkDate(int date);
    string dateIntToString(int date);
    int dateStringToInt(string date);
private:
    int howManyDaysMonth(int year, int month);
};
