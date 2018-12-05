#include <iostream>
#include "fileIncome.h"
#include <vector>

using namespace std;

class Incomings{
    string userLoginLoggedIn;
    vector<Income> incomings;
public:
    FileIncome fileIncome;

    void addIncome();
    double getIncomeThisMonth();
    double getIncomeLastMonth();
    double getIncomeChoosenDate(int firstDate, int secondDate);

    void clearVector();

    void setUserLoginLoggedIn(string userLoginLoggedIn);
    string getUserLoginLoggedIn();
private:
    char changeToSmallWhenNeeded (char letterBefore);
    void displayStringTop();
    void saveQuestion(string, string, double);
};
