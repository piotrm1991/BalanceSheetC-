#include <iostream>
#include "incomings.h"
#include <algorithm>

using namespace std;

void Incomings::displayStringTop() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>DODAWANIE PRZYCHODU<<<"<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void Incomings::saveQuestion(string date, string name, double amount) {
    system("cls");
    displayStringTop();

    cout<<"Data: "<<date<<endl;
    cout<<"Opis: "<<name<<endl;
    cout<<"Kwota: "<<amount<<endl;

    Date dateFunctions;
    int dateInt = dateFunctions.dateStringToInt(date);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Czy napewno chcesz zapisac ten przychod(t/n)"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    char userInput;
    while(true) {
        char answerChoice;
        cin>>userInput;
        answerChoice=changeToSmallWhenNeeded(userInput);

        switch (answerChoice) {
        case't': {
            fileIncome.income.setUserLogin(userLoginLoggedIn);
            fileIncome.income.setDate(dateInt);
            fileIncome.income.setName(name);
            fileIncome.income.setAmount(amount);
            fileIncome.addIncome();
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
void Incomings::addIncome() {
    system("cls");
    displayStringTop();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Czy chcesz dodac przychod z dzisiejsza data?(t/n)"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    {
        char userInput;
        while(true) {
            char answerChoice;
            cin>>userInput;
            answerChoice=changeToSmallWhenNeeded(userInput);

            switch (answerChoice) {
            case't': {
                system("cls");
                displayStringTop();

                Date dateFunctions;
                PresentDate presentDate;
                Amount amount;
                Conversion conversion;

                string date;
                date = dateFunctions.dateIntToString(presentDate.getDatePresent());

                string amountString;
                double amountDouble = 0;

                while(true) {
                    cout<<"Podaj kwote: ";
                    cin>>amountString;

                    amount.changeCommaToDot(amountString);

                    if (amount.checkAmountDigit(amountString)==false) {
                        cout<<"Podano nieprawidlowe dane. Sprobuj ponownie..."<<endl;
                    }
                    if (amount.checkAmountDigit(amountString)==true) {

                        amountDouble = conversion.stringToDouble(amountString);

                        if (amount.checkAmountValue(amountDouble)==false) {
                            cout<<"Kwota nie moze byc mniejsza ani rowna 0! Sprobuj ponownie..."<<endl;
                        }

                        if (amount.checkAmountValue(amountDouble)==true) {
                            break;
                        }
                    }
                }

                system("cls");
                displayStringTop();

                cout<<"Data: "<<date<<endl;
                cout<<"Kwota: "<<amountDouble<<endl;

                string name;
                cout<<"Podaj opis przychodu: ";
                cin>>name;
                saveQuestion(date, name, amountDouble);
                return;
            }
            break;
            case'n': {
                system("cls");
                displayStringTop();

                Date dateFunctions;
                PresentDate presentDate;
                Conversion conversion;

                string date;
                cout<<"Podaj date w formacie rrrr-mm-dd np. "<<dateFunctions.dateIntToString(presentDate.getDatePresent())<<" : ";
                cin>>date;
                int dateInt = dateFunctions.dateStringToInt(date);

                if (dateFunctions.checkDate(dateInt)==true) {
                    Amount amount;

                    string amountString;
                    double amountDouble = 0;

                    while(true) {
                        cout<<"Podaj kwote: ";
                        cin>>amountString;

                        amount.changeCommaToDot(amountString);

                        if (amount.checkAmountDigit(amountString)==false) {
                            cout<<"Podano nieprawidlowe dane. Sprobuj ponownie..."<<endl;
                        }
                        if (amount.checkAmountDigit(amountString)==true) {

                            amountDouble = conversion.stringToDouble(amountString);

                            if (amount.checkAmountValue(amountDouble)==false) {
                                cout<<"Kwota nie moze byc mniejsza ani rowna 0! Sprobuj ponownie..."<<endl;
                            }

                            if (amount.checkAmountValue(amountDouble)==true) {
                                break;
                            }
                        }
                    }

                    system("cls");
                    displayStringTop();

                    cout<<"Data: "<<date<<endl;
                    cout<<"Kwota: "<<amountDouble<<endl;

                    string name;
                    cout<<"Podaj opis przychodu: ";
                    cin>>name;
                    saveQuestion(date, name, amountDouble);
                } else {
                    cout<<"Podano nieprawidlowe dane. Powrot do menu glownego..."<<endl;
                    Sleep(3000);
                }
                return;
            }
            break;
            }
        }
    }
}
double Incomings::getIncomeThisMonth() {
    Date dateFunctions;
    double incomingsTotal = 0;

    incomings = fileIncome.getIncomeThisMonth();
    fileIncome.clearVector();
    sort(incomings.begin(), incomings.end());
    for (vector<Income>::iterator itr=incomings.begin(); itr !=incomings.end(); itr++) {
        cout<<"Data: "<<dateFunctions.dateIntToString(itr->getDate())<<" Kwota: "<<itr->getAmount()<<" Opis: "<<itr->getName()<<endl;
        incomingsTotal+=itr->getAmount();
    }
    return incomingsTotal;
}
double Incomings::getIncomeLastMonth() {
    Date dateFunctions;
    double incomingsTotal = 0;

    incomings = fileIncome.getIncomeLastMonth();
    fileIncome.clearVector();
    sort(incomings.begin(), incomings.end());
    for (vector<Income>::iterator itr=incomings.begin(); itr !=incomings.end(); itr++) {
        cout<<"Data: "<<dateFunctions.dateIntToString(itr->getDate())<<" Kwota: "<<itr->getAmount()<<" Opis: "<<itr->getName()<<endl;
        incomingsTotal+=itr->getAmount();
    }
    return incomingsTotal;
}
double Incomings::getIncomeChoosenDate(int firstDate, int secondDate) {
    Date dateFunctions;
    double incomingsTotal = 0;

    incomings = fileIncome.getIncomeChoosenDate(firstDate, secondDate);
    fileIncome.clearVector();
    sort(incomings.begin(), incomings.end());
    for (vector<Income>::iterator itr=incomings.begin(); itr !=incomings.end(); itr++) {
        cout<<"Data: "<<dateFunctions.dateIntToString(itr->getDate())<<" Kwota: "<<itr->getAmount()<<" Opis: "<<itr->getName()<<endl;
        incomingsTotal+=itr->getAmount();
    }
    return incomingsTotal;
}
void Incomings::clearVector() {
    incomings.clear();
}
char Incomings::changeToSmallWhenNeeded (char letterBefore) {
    char letterAfter=letterBefore;
    if(not islower(letterBefore)) {
        letterAfter=tolower(letterBefore);
    }
    return letterAfter;
}

void Incomings::setUserLoginLoggedIn(string userLoginLoggedIn) {
    this->userLoginLoggedIn = userLoginLoggedIn;
}

string Incomings::getUserLoginLoggedIn() {
    return userLoginLoggedIn;
}
