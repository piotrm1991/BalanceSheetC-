#include <iostream>
#include "users.h"
#include <algorithm>

using namespace std;

string Users::changeFirstLetterCapital(string word) {
    if(!word.empty()) {
        transform(word.begin(),word.end(), word.begin(),::tolower);
        word[0]=toupper(word[0]);
    }
    return word;
}
char Users::changeToSmallWhenNeeded (char letterBefore) {
    char letterAfter=letterBefore;
    if(not islower(letterBefore)) {
        letterAfter=tolower(letterBefore);
    }
    return letterAfter;
}
void Users::displayStringTopNewUser() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>REJESTRACJA NOWEGO UZYTKOWNIKA<<<"<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void Users::displayStringTopPasswordChange() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>ZMIANA HASLA<<<"<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void Users::displayStringTopLogIn() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>LOGOWANIE<<<"<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void Users::changePassword(){
    system("cls");
    displayStringTopPasswordChange();

    cout<<endl<<"Jestes zalogowany jako: >> "<<getUserLoginLoggedIn()<<" <<"<<endl<<endl;
    string passwordNew;
    cout<<"Podaj nowe haslo: ";
    cin>>passwordNew;

    system("cls");
    displayStringTopPasswordChange();

    cout<<"Stare haslo: >> "<<getUserPasswordLoggedIn()<<" <<"<<endl;
    cout<<"Nowe haslo: >> "<<passwordNew<<" <<"<<endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Czy na pewno chcesz zmienic swoje haslo?(t/n)"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    char userInput;
    while(true) {
        char answerChoice;
        cin>>userInput;
        answerChoice=changeToSmallWhenNeeded(userInput);

        switch (answerChoice) {
        case 't': {
            fileUsers.changePassword(getUserLoginLoggedIn(), passwordNew);
            setUserPasswordLoggedIn(passwordNew);
            cout<<endl<<"Haslo ZOSTALO zmienione."<<endl;
            Sleep(1000);
            return;
        }
        break;
        case 'n': {
            cout<<endl<<"Haslo NIE zostalo zmienione."<<endl<<endl;
            return;
        }
        break;
        }
    }
}
void Users::addNewUser() {
    system("cls");
    displayStringTopNewUser();

    string loginNew;
    cout<<"Podaj nazwe uzytkownika: ";
    cin>>loginNew;

    while (true) {
        if (fileUsers.checkIfExists(loginNew)==false) {
            cout<<"Taki uzytykownik istnieje. Wpisz inna nazwe uzytkownika: ";
            cin>>loginNew;
        } else {
            break;
        }
    }

    string passwordNew;
    cout<<"Podaj haslo: ";
    cin>>passwordNew;

    string nameNew;
    cout<<"Podaj imie uzytkownika: ";
    cin>>nameNew;

    string surnameNew;
    cout<<"Podaj nazwisko uzytkownika: ";
    cin>>surnameNew;

    system("cls");
    displayStringTopNewUser();

    int userIdNew = fileUsers.getNumberOfUsers();
    cout<<"Id uzytkownika: "<<++userIdNew<<endl;
    cout<<"Nazwa uzytkownika: "<<loginNew<<endl;
    cout<<"Haslo uzytkownika: "<<passwordNew<<endl;
    cout<<"Imie uzytkownika: "<<changeFirstLetterCapital(nameNew)<<endl;
    cout<<"Nazwisko uzytkownika: "<<changeFirstLetterCapital(surnameNew)<<endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Czy chcesz utworzyc takiego UZYTKOWNIKA?(t/n)"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    char userInput;
    while(true) {
        char answerChoice;
        cin>>userInput;
        answerChoice=changeToSmallWhenNeeded(userInput);

        switch (answerChoice) {
        case't': {
            fileUsers.assignUserId();
            fileUsers.user.setUserLogin(loginNew);
            fileUsers.user.setUserPassword(passwordNew);
            fileUsers.user.setUserName(changeFirstLetterCapital(nameNew));
            fileUsers.user.setUserSurname(changeFirstLetterCapital(surnameNew));
            fileUsers.appendUser();
            return;
        }
        break;
        case'n': {
            return;
        }
        break;
        }
    }
}

void Users::signIn() {
    system("cls");
    displayStringTopLogIn();

    cout<<"Podaj nazwe uzytkownika: ";
    string login;
    cin>>login;
    if (fileUsers.checkIfExists(login)==false) {
        fileUsers.loadOneUser(login);
        for (int attempt=0; attempt<3; attempt++) {
            cout<<"Podaj haslo. Pozostalo prob "<<3-attempt<<": ";
            string password;
            cin>>password;

            if (fileUsers.user.getUserPassword()==password) {
                cout<<"Zalogowales sie. Wczytuje ksiazke adresowa..."<<endl;
                setUserIdLoggedIn(fileUsers.user.getUserId());
                setUserLoginLoggedIn(fileUsers.user.getUserLogin());
                setUserPasswordLoggedIn(fileUsers.user.getUserPassword());
                setUserNameLoggedIn(fileUsers.user.getUserName());
                setUserSurnameLoggedIn(fileUsers.user.getUserSurname());
                Sleep(1000);
                return;
            }
        }
        cout<<"Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba"<<endl;
        Sleep(3000);
        return;
    }

    else {
        cout<<"Nie ma uzytkownika z takim loginem."<<endl;
        Sleep(3000);
    }
    return;
}
Users::Users(int userIdLoggedIn, string userLoginLoggedIn, string userPasswordLoggedIn, string userNameLoggedIn, string userSurnameLoggedIn) {
    this->userIdLoggedIn=userIdLoggedIn;
    this->userLoginLoggedIn=userLoginLoggedIn;
    this->userPasswordLoggedIn=userPasswordLoggedIn;
    this->userNameLoggedIn = userNameLoggedIn;
    this->userSurnameLoggedIn = userSurnameLoggedIn;
}
void Users::logOut(int userIdLoggedIn, string userLoginLoggedIn, string userPasswordLoggedIn, string userNameLoggedIn, string userSurnameLoggedIn) {
    this->userIdLoggedIn = userIdLoggedIn;
    this->userLoginLoggedIn = userLoginLoggedIn;
    this->userPasswordLoggedIn = userPasswordLoggedIn;
    this->userNameLoggedIn = userNameLoggedIn;
    this->userSurnameLoggedIn = userSurnameLoggedIn;
}

void Users::setUserIdLoggedIn(int userIdLoggedIn) {
    this->userIdLoggedIn=userIdLoggedIn;
}
void Users::setUserLoginLoggedIn(string userLoginLoggedIn) {
    this->userLoginLoggedIn=userLoginLoggedIn;
}
void Users::setUserPasswordLoggedIn(string userPasswordLoggedIn) {
    this->userPasswordLoggedIn=userPasswordLoggedIn;
}
void Users::setUserNameLoggedIn(string userNameLoggedIn) {
    this->userNameLoggedIn=userNameLoggedIn;
}
void Users::setUserSurnameLoggedIn(string userSurnameLoggedIn) {
    this->userSurnameLoggedIn=userSurnameLoggedIn;
}

int Users::getUserIdLoggedIn() {
    return userIdLoggedIn;
}
string Users::getUserLoginLoggedIn() {
    return userLoginLoggedIn;
}
string Users::getUserPasswordLoggedIn() {
    return userPasswordLoggedIn;
}
string Users::getUserNameLoggedIn() {
    return userNameLoggedIn;
}
string Users::getUserSurnameLoggedIn() {
    return userSurnameLoggedIn;
}

