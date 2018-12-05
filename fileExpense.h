#include <iostream>
#include "file.h"
#include "expense.h"
#include <vector>

using namespace std;

class FileExpense :public File{
    int numberOfEntries;
    string userLoginLoggedIn;
    vector<Expense>downloadedExpenses;
public:
    Expense expense;
    FileExpense (string = "expense.xml");

    void addExpense();
    vector<Expense> getExpenseThisMonth();
    vector<Expense> getExpenseLastMonth();
    vector<Expense> getExpenseChoosenDate(int firstDate, int secondDate);

    void setNumberEntriesIfNeeded();
    void setUserLoginLoggedIn(string userLoginLoggedIn);

    string getUserLoginLoggedIn();
    int getNumberOfEntries();

    void clearVector();
};
