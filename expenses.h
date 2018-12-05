#include <iostream>
#include "fileExpense.h"
#include <vector>

using namespace std;

class Expenses{
    string userLoginLoggedIn;
    vector<Expense> expenses;
public:
    FileExpense fileExpense;

    void addExpense();
    double getExpenseThisMonth();
    double getExpenseLastMonth();
    double getExpenseChoosenDate(int firstDate, int secondDate);

    void clearVector();

    void setUserLoginLoggedIn(string userLoginLoggedIn);
    string getUserLoginLoggedIn();
private:
    char changeToSmallWhenNeeded (char letterBefore);
    void displayStringTop();
    void saveQuestion(string, string, double);
};
