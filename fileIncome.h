#include <iostream>
#include "file.h"
#include "income.h"
#include <vector>

using namespace std;

class FileIncome :public File{
    int numberOfEntries;
    string userLoginLoggedIn;
    vector<Income>downloadedIncomings;
public:
    Income income;
    FileIncome (string = "income.xml");

    void addIncome();
    vector<Income> getIncomeThisMonth();
    vector<Income> getIncomeLastMonth();
    vector<Income> getIncomeChoosenDate(int firstDate, int secondDate);

    void setNumberEntriesIfNeeded();
    void setUserLoginLoggedIn(string userLoginLoggedIn);

    string getUserLoginLoggedIn();
    int getNumberOfEntries();

    void clearVector();
};

