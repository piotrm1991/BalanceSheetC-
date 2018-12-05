#include <iostream>
#include "mainMenu.h"
#include <windows.h>
#include "balanceSheet.h"

using namespace std;

BalanceSheet balanceSheet;

void MainMenu::runMainMenu(){
balanceSheet.incomings.fileIncome.creatIncomeFileIfNeeded();
balanceSheet.incomings.setUserLoginLoggedIn(userLoginLoggedIn);
balanceSheet.incomings.fileIncome.setUserLoginLoggedIn(userLoginLoggedIn);
balanceSheet.incomings.fileIncome.setNumberEntriesIfNeeded();

balanceSheet.expenses.fileExpense.creatExpenseFileIfNeeded();
balanceSheet.expenses.setUserLoginLoggedIn(userLoginLoggedIn);
balanceSheet.expenses.fileExpense.setUserLoginLoggedIn(userLoginLoggedIn);
balanceSheet.expenses.fileExpense.setNumberEntriesIfNeeded();

    char userInputChoice;
    while(true) {
        system("cls");
        cout<<"Witaj >>> "<<getUserNameLoggedIn()<<" "<<getUserSurnameLoggedIn()<<" <<<"<<endl;
        cout<<endl;
        cout<<"1. Dodaj przychod."<<endl;
        cout<<"2. Dodaj wydatek."<<endl;
        cout<<"3. Bilans z bierzacego miesiaca."<<endl;
        cout<<"4. Bilans z poprzedniego miesiaca."<<endl;
        cout<<"5. Bilans z wybranego okresu."<<endl;
        cout<<"6. Zmien haslo."<<endl;
        cout<<"9. Wyloguj sie."<<endl;
        cout<<endl<<"Wybierz 1-9: ";
        cin>>userInputChoice;

        switch (userInputChoice) {
        case'1': {
            addIncome();
        }
        break;
        case'2': {
           addExpense();
        }
        break;
        case'3': {
            balanceSheetThisMonth();
        }
        break;
        case'4': {
            balanceSheetLastMonth();
        }
        break;
        case'5': {
            balanceSheetChoosenDate();
        }
        break;
        case'6': {
            changePassword();
            return;
        }
        break;
        case'9': {
            logOut();
            return;
        }
        break;
        }
    }

}
MainMenu::MainMenu(int userIdLoggedIn, string userLoginLoggedIn, string userNameLoggedIn, string userSurnameLoggedIn, bool answerPasswordChange){
    this->userIdLoggedIn = userIdLoggedIn;
    this->userLoginLoggedIn = userLoginLoggedIn;
    this->userNameLoggedIn = userNameLoggedIn;
    this->userSurnameLoggedIn = userSurnameLoggedIn;
    this->answerPasswordChange = answerPasswordChange;
}

void MainMenu::changePassword(){
    setAnswerPasswordChangeTrue();
}
void MainMenu::logOut(){
    setUserIdLoggedIn(0);
    setUserLoginLoggedIn("");
    setUserNameLoggedIn("");
    setUserSurnameLoggedIn("");
}
void MainMenu::addIncome(){
    balanceSheet.incomings.addIncome();
}
void MainMenu::addExpense(){
    balanceSheet.expenses.addExpense();
}
void MainMenu::balanceSheetThisMonth(){
    balanceSheet.balanceSheetThisMonth();
}
void MainMenu::balanceSheetLastMonth(){
    balanceSheet.balanceSheetLastMonth();
}
void MainMenu::balanceSheetChoosenDate(){
    balanceSheet.balanceSheetChoosenDate();

}


void MainMenu::setAnswerPasswordChangeTrue(bool answerPasswordChange){
    this->answerPasswordChange = answerPasswordChange;
}
void MainMenu::setAnswerPasswordChangeFalse(bool answerPasswordChange){
    this->answerPasswordChange = answerPasswordChange;
}
bool MainMenu::getAnswerPasswordChange(){
    return answerPasswordChange;
}

void MainMenu::setUserIdLoggedIn(int userIdLoggedIn){
    this->userIdLoggedIn = userIdLoggedIn;
}
void MainMenu::setUserLoginLoggedIn(string userLoginLoggedIn){
    this->userLoginLoggedIn = userLoginLoggedIn;
}
void MainMenu::setUserNameLoggedIn(string userNameLoggedIn) {
    this->userNameLoggedIn=userNameLoggedIn;
}
void MainMenu::setUserSurnameLoggedIn(string userSurnameLoggedIn) {
    this->userSurnameLoggedIn=userSurnameLoggedIn;
}

int MainMenu::getUserIdLoggedIn(){
    return userIdLoggedIn;
}
string MainMenu::getUserLoginLoggedIn(){
    return userLoginLoggedIn;
}
string MainMenu::getUserNameLoggedIn() {
    return userNameLoggedIn;
}
string MainMenu::getUserSurnameLoggedIn() {
    return userSurnameLoggedIn;
}
