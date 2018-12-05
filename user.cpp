#include <iostream>
#include "user.h"

using namespace std;

void User::setUserId(int userId){
    this->userId=userId;
}
void User::setUserLogin(string userLogin){
    this->userLogin=userLogin;
}
void User::setUserPassword(string userPassword){
    this->userPassword=userPassword;
}
void User::setUserName(string userName){
    this->userName=userName;
}
void User::setUserSurname(string userSurname){
    this->userSurname=userSurname;
}

int User::getUserId(){
    return userId;
}
string User::getUserLogin(){
    return userLogin;
}
string User::getUserPassword(){
    return userPassword;
}
string User::getUserName(){
    return userName;
}
string User::getUserSurname(){
    return userSurname;
}

User::User(int userId, string userLogin, string userPassword) {
    this->userId=userId;
    this->userLogin=userLogin;
    this->userPassword=userPassword;
}
