#include <iostream>
#include "conversion.h"
#include <sstream>
#include <stdlib.h>

using namespace std;

string Conversion::intToString (int number) {
    ostringstream ss;
    ss<<number;
    string word=ss.str();
    return word;
}
int Conversion::stringToInt(string word) {
    int number;
    istringstream iss(word);
    iss >> number;
    return number;
}
double Conversion::stringToDouble(string amountString){
    double amountDouble = atof(amountString.c_str());
    return amountDouble;
}
string Conversion::doubleToString(double amountDouble){
    string amountString = "";
    ostringstream oss;
    oss<<amountDouble;
    amountString = oss.str();
    return amountString;
}
