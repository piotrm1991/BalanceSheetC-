#include <iostream>

using namespace std;

class User{
    int userId;
    string userLogin;
    string userPassword;
    string userName;
    string userSurname;
public:
    User(int=0, string=" ", string=" ");

    void setUserId(int userId);
    void setUserLogin(string userLogin);
    void setUserPassword(string userPassword);
    void setUserName(string userName);
    void setUserSurname(string userSurname);

    int getUserId();
    string getUserLogin();
    string getUserPassword();
    string getUserName();
    string getUserSurname();

    void assignUserId();
};
