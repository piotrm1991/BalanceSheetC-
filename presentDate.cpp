#include <iostream>
#include "presentDate.h"
#include <windows.h>
#include <winbase.h>

using namespace std;

PresentDate::PresentDate(){
    SYSTEMTIME st;
    GetSystemTime(&st);
    this->year = st.wYear;
    this->month = st.wMonth;
    this->day = st.wDay;
    this->date = year*10000+month*100+day;
}
int PresentDate::getYearPresent(){
    return year;
}
int PresentDate::getMonthPresent(){
    return month;
}
int PresentDate::getDayPresent(){
    return day;
}
int PresentDate::getDatePresent(){
    return date;
}
