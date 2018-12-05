#include <iostream>
#include "user.h"
#include <windows.h>
#include "file.h"

using namespace std;

class FileUsers :public File {
    int numberOfUsers;
public:
    User user;
    FileUsers(string = "users.xml");

    void downloadNumberOfUsers();
    void setNumberOfUsers(int numberOfUsers);
    int getNumberOfUsers();

    void changePassword(string login, string passwordNew);
    void loadOneUser(string login);
    void assignUserId();
    bool checkIfExists(string login);
    void appendUser();
};
