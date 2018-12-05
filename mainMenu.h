#include <iostream>

using namespace std;

class MainMenu{
    int userIdLoggedIn;
    string userLoginLoggedIn;
    string userNameLoggedIn;
    string userSurnameLoggedIn;
    bool answerPasswordChange;
public:
    MainMenu(int = 0, string = "", string = "", string = "", bool = false);
    void runMainMenu();
    void addIncome();
    void addExpense();
    void balanceSheetThisMonth();
    void balanceSheetLastMonth();
    void balanceSheetChoosenDate();
    void changePassword();
    void logOut();

    void setAnswerPasswordChangeFalse(bool = false);
    void setAnswerPasswordChangeTrue(bool = true);
    bool getAnswerPasswordChange();

    void setUserIdLoggedIn(int userIdLoggedIn);
    void setUserLoginLoggedIn(string userLoginLoggedIn);
    void setUserNameLoggedIn(string userNameLoggedIn);
    void setUserSurnameLoggedIn(string userSurnameLoggedIn);

    int getUserIdLoggedIn();
    string getUserLoginLoggedIn();
    string getUserNameLoggedIn();
    string getUserSurnameLoggedIn();
};
