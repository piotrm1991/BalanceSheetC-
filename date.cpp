#include <iostream>
#include "date.h"

using namespace std;

int Date::howManyDaysMonth(int year, int month){
    int numberOfDays = 0;
        bool bissextile=false;
    if((year%4==0 && year%100!=0) || year%400==0) {
        bissextile=true;
    }
    switch(month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        numberOfDays = 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        numberOfDays = 30;
        break;

    case 2:
        if(bissextile) {
                numberOfDays = 29;
        } else {
            numberOfDays = 28;
        }
        break;
    default: {
        numberOfDays = 32;
    }
    }
    return numberOfDays;
}
bool Date::checkDate(int date){
    PresentDate presentDate;
    int dayDate = date%100;
    date-=dayDate;
    int monthDate = (date%10000)/100;
    date-=monthDate;
    int yearDate = date/10000;

    if(date<20000101||date>presentDate.getDatePresent()){
        return false;
    }
    if(howManyDaysMonth(yearDate, monthDate)==32){
        return false;
    }
    if(dayDate<1||dayDate>howManyDaysMonth(yearDate, monthDate)){
        return false;
    }
return true;
}
int Date::dateStringToInt(string date) {
    Conversion conversion;
    int dateInt = 0;
    string dateStringWithoutMarkers = "";
    for(int i=0; i<10; i++) {
        switch(i) {
        case 0:
            dateStringWithoutMarkers+=date[i];
            break;
        case 1:
            dateStringWithoutMarkers+=date[i];
            break;
        case 2:
            dateStringWithoutMarkers+=date[i];
            break;
        case 3:
            dateStringWithoutMarkers+=date[i];
            break;
        case 4:
            break;
        case 5:
            dateStringWithoutMarkers+=date[i];
            break;
        case 6:
            dateStringWithoutMarkers+=date[i];
            break;
        case 7:
            break;
        case 8:
            dateStringWithoutMarkers+=date[i];
            break;
        case 9:
            dateStringWithoutMarkers+=date[i];
            break;
        }
    }
    dateInt = conversion.stringToInt(dateStringWithoutMarkers);
    return dateInt;
}
string Date::dateIntToString(int date) {
    Conversion conversion;
    string dateString = conversion.intToString(date);
    string dateStringMarker = "";
    string year = "";
    string month = "";
    string day = "";
    char marker = '-';

    for(int i=0; i<8; i++) {
        switch(i) {
        case 0:
            year+=dateString[i];
            break;
        case 1:
            year+=dateString[i];
            break;
        case 2:
            year+=dateString[i];
            break;
        case 3:
            year+=dateString[i];
            break;
        case 4:
            month+=dateString[i];
            break;
        case 5:
            month+=dateString[i];
            break;
        case 6:
            day+=dateString[i];
            break;
        case 7:
            day+=dateString[i];
            break;
        }
    }
    dateStringMarker=year+marker+month+marker+day;
    return dateStringMarker;
}
