#include <iostream>
#include "fileUsers.h"

using namespace std;

class Users {
    int userIdLoggedIn;
    string userLoginLoggedIn;
    string userPasswordLoggedIn;
    string userNameLoggedIn;
    string userSurnameLoggedIn;
public:
    FileUsers fileUsers;
    Users (int = 0, string = "", string = "", string = "", string = "");

    void addNewUser();
    void signIn();
    void changePassword();
    void logOut(int = 0, string = "", string = "", string = "", string = "");

    void setUserIdLoggedIn(int userIdLoggedIn);
    void setUserLoginLoggedIn(string userLoginLoggedIn);
    void setUserPasswordLoggedIn(string userPasswordLoggedIn);
    void setUserNameLoggedIn(string userNameLoggedIn);
    void setUserSurnameLoggedIn(string userSurnameLoggedIn);

    int getUserIdLoggedIn();
    string getUserLoginLoggedIn();
    string getUserPasswordLoggedIn();
    string getUserNameLoggedIn();
    string getUserSurnameLoggedIn();

private:
    char changeToSmallWhenNeeded (char letterBefore);
    void displayStringTopNewUser();
    void displayStringTopPasswordChange();
    void displayStringTopLogIn();
    string changeFirstLetterCapital(string word);
};
