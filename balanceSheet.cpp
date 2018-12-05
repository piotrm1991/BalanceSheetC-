#include <iostream>
#include "balanceSheet.h"
#include <conio.h>
#include "file.h"

using namespace std;
void BalanceSheet::displayStringTopThisMonth() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>BILANS Z BIERZACEGO MIESIACA<<<"<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void BalanceSheet::displayStringTopLastMonth() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>BILANS Z OSTATNIEGO MIESIACA<<<"<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void BalanceSheet::displayStringTopChoosenDate() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>BILANS Z WYBRANEGO OKRESU<<<"<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void BalanceSheet::balanceSheetThisMonth() {
    system("cls");
    displayStringTopThisMonth();

    double incomingsTotal = 0;
    incomingsTotal = incomings.getIncomeThisMonth();
    if(incomingsTotal==0) {
        cout<<"Nie ma przychodow w tym miesiacu."<<endl;
    } else {
        cout<<endl<<"Suma przychodow: "<<incomingsTotal<<endl<<endl;
    }

    double expensesTotal = 0;
    expensesTotal = expenses.getExpenseThisMonth();
    if(expensesTotal==0) {
        cout<<"Nie ma wydatkow w tym miesiacu."<<endl;
    } else {
        cout<<endl<<"Suma wydatkow: "<<expensesTotal<<endl<<endl;
    }

    double incomingsAndExpensesTotal = incomingsTotal - expensesTotal;
    cout<<"Suma przychodow i wydatkow to: "<<incomingsAndExpensesTotal<<endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();

    incomings.clearVector();
    expenses.clearVector();
}
void BalanceSheet::balanceSheetLastMonth() {
    system("cls");
    displayStringTopLastMonth();

    double incomingsTotal = 0;
    incomingsTotal = incomings.getIncomeLastMonth();
    if(incomingsTotal==0) {
        cout<<"Nie ma przychodow w tym z zeszlego miesiaca."<<endl;
    } else {
        cout<<endl<<"Suma przychodow: "<<incomingsTotal<<endl<<endl;
    }

    double expensesTotal = 0;
    expensesTotal = expenses.getExpenseLastMonth();
    if(expensesTotal==0) {
        cout<<"Nie ma wydatkow w tym miesiacu."<<endl;
    } else {
        cout<<endl<<"Suma wydatkow: "<<expensesTotal<<endl<<endl;
    }

    double incomingsAndExpensesTotal = incomingsTotal - expensesTotal;
    cout<<"Suma przychodow i wydatkow to: "<<incomingsAndExpensesTotal<<endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();

    incomings.clearVector();
    expenses.clearVector();
}
void BalanceSheet::balanceSheetChoosenDate() {
    system("cls");
    displayStringTopChoosenDate();

    Date dateFunctions;
    PresentDate presentDate;

    string choosenDateFirst;
    string choosenDateSecond;

    cout<<"Podaj poczatkowa date wybranego okresu w formacie rrrr-mm-dd np. "<<dateFunctions.dateIntToString(presentDate.getDatePresent())<<":"<<endl;
    cin>>choosenDateFirst;
    int choosenDateFirstInt = dateFunctions.dateStringToInt(choosenDateFirst);

    while (dateFunctions.checkDate(choosenDateFirstInt)==false) {
        cout<<"Niepoprawna data. Podaj date w formacie rrrr-mm-dd: ";
        cin>>choosenDateFirst;
        choosenDateFirstInt = dateFunctions.dateStringToInt(choosenDateFirst);
    }

    cout<<"Podaj koncowa date wybranego okresu w formacie rrrr-mm-dd np. "<<dateFunctions.dateIntToString(presentDate.getDatePresent())<<":"<<endl;
    cin>>choosenDateSecond;
    int choosenDateSecondInt = dateFunctions.dateStringToInt(choosenDateSecond);

    while (dateFunctions.checkDate(choosenDateSecondInt)==false) {
        cout<<"Niepoprawna data. Podaj date w formacie rrrr-mm-dd: ";
        cin>>choosenDateSecond;
        choosenDateSecondInt = dateFunctions.dateStringToInt(choosenDateSecond);
    }

    {
        system("cls");
        displayStringTopChoosenDate();

        double incomingsTotal = 0;
        incomingsTotal = incomings.getIncomeChoosenDate(choosenDateFirstInt, choosenDateSecondInt);
        if(incomingsTotal==0) {
            cout<<"Nie ma przychodow w tym okresie."<<endl;
        } else {
            cout<<endl<<"Suma przychodow: "<<incomingsTotal<<endl<<endl;
        }

        double expensesTotal = 0;
        expensesTotal = expenses.getExpenseChoosenDate(choosenDateFirstInt, choosenDateSecondInt);
        if(expensesTotal==0) {
            cout<<"Nie ma wydatkow w tym okresie."<<endl;
        } else {
            cout<<endl<<"Suma wydatkow: "<<expensesTotal<<endl<<endl;
        }

        double incomingsAndExpensesTotal = incomingsTotal - expensesTotal;
        cout<<"Roznica przychodow i wydatkow to: "<<incomingsAndExpensesTotal<<endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        getch();

        incomings.clearVector();
        expenses.clearVector();
    }
}
