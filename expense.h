#include <iostream>
#include "date.h"
#include "amount.h"

using namespace std;

class Expense {
    int date;
    string name;
    double amount;
    string userLoginLoggedIn;
public:
    void setDate(int date);
    void setName(string name);
    void setAmount(double amount);
    void setUserLogin(string userLoginLoggedIn);

    int getDate();
    string getName();
    double getAmount();
    string getUserLogin();

    bool operator < (Expense second);
};
