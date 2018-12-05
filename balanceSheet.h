#include <iostream>
#include "incomings.h"
#include "expenses.h"

using namespace std;

class BalanceSheet{

public:
    Incomings incomings;
    Expenses expenses;

    void balanceSheetThisMonth();
    void balanceSheetLastMonth();
    void balanceSheetChoosenDate();
private:
    void displayStringTopThisMonth();
    void displayStringTopLastMonth();
    void displayStringTopChoosenDate();
};
