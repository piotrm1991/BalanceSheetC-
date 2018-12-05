#include <iostream>
#include "fileUsers.h"
#include <sstream>

using namespace std;

FileUsers::FileUsers(string nameFile) {
    this->nameFile=nameFile;
}
void FileUsers::setNumberOfUsers(int numberOfUsers) {
    this->numberOfUsers = numberOfUsers;
}
int FileUsers::getNumberOfUsers() {
    return numberOfUsers;
}
void FileUsers::assignUserId() {
    user.setUserId(++numberOfUsers);
}
void FileUsers::downloadNumberOfUsers() {
    CMarkup xmlFile;
    if (xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("USERS");
        setNumberOfUsers(atoi(MCD_2PCSZ(xmlFile.GetAttrib("numberOfUsers"))));
    } else {
        exit(0);
    }
}
void FileUsers::appendUser() {
    CMarkup xmlFile;
    if (xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("USERS");
        setNumberOfUsers(user.getUserId());
        xmlFile.SetAttrib("numberOfUsers", user.getUserId());
        xmlFile.IntoElem();
        xmlFile.AddElem(user.getUserLogin());
        xmlFile.IntoElem();
        xmlFile.AddElem("ID", user.getUserId());
        xmlFile.AddElem("PASSWORD", user.getUserPassword());
        xmlFile.AddElem("NAME", user.getUserName());
        xmlFile.AddElem("SURNAME", user.getUserSurname());
        xmlFile.Save(nameFile.c_str());
    } else {
        cout<<"Nie mozna otworzyc pliku: "<<nameFile<<endl;
        system("pause");
    }
}
bool FileUsers::checkIfExists(string login) {
    CMarkup xmlFile;
    if (xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("USERS");
        xmlFile.IntoElem();
        if (xmlFile.FindElem(login)) {
            return false;
        } else {
            return true;
        }
    } else {
        exit(0);
    }
}
void FileUsers::loadOneUser(string login){
    CMarkup xmlFile;
    if (xmlFile.Load(nameFile.c_str())){
        xmlFile.FindElem("USERS");
        xmlFile.IntoElem();
        xmlFile.FindElem(login);
        xmlFile.IntoElem();
        user.setUserLogin(login);
        xmlFile.FindElem("ID");
        user.setUserId(atoi(MCD_2PCSZ(xmlFile.GetData())));
        xmlFile.ResetMainPos();
        xmlFile.FindElem("PASSWORD");
        user.setUserPassword(xmlFile.GetData());
        xmlFile.ResetMainPos();
        xmlFile.FindElem("NAME");
        user.setUserName(xmlFile.GetData());
        xmlFile.ResetMainPos();
        xmlFile.FindElem("SURNAME");
        user.setUserSurname(xmlFile.GetData());
        xmlFile.ResetMainPos();
    }
}
void FileUsers::changePassword(string login, string passwordNew){
    CMarkup xmlFile;
    if (xmlFile.Load(nameFile.c_str())){
        xmlFile.FindElem("USERS");
        xmlFile.IntoElem();
        xmlFile.FindElem(login);
        xmlFile.IntoElem();
        xmlFile.FindElem("PASSWORD");
        xmlFile.SetData(passwordNew);
        xmlFile.Save(nameFile.c_str());
    }
}
