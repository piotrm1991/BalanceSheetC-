#include <iostream>
#include "fileExpense.h"

using namespace std;

FileExpense::FileExpense(string nameFile) {
    this->nameFile = nameFile;
}
void FileExpense::clearVector() {
    downloadedExpenses.clear();
}
vector<Expense> FileExpense::getExpenseThisMonth() {
    Date dateFunctions;
    PresentDate presentDate;
    Conversion conversion;

    int monthThis = presentDate.getYearPresent()*10000+presentDate.getMonthPresent()*100;

    CMarkup xmlFile;
    if(xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("EXPENSES");
        xmlFile.IntoElem();
        if(xmlFile.FindElem(userLoginLoggedIn)) {
            xmlFile.IntoElem();
            xmlFile.ResetMainPos();

            for (int i=0; i<numberOfEntries; i++) {
                xmlFile.FindElem("ENTRY");
                xmlFile.IntoElem();
                xmlFile.FindElem("DATE");
                if(dateFunctions.dateStringToInt(xmlFile.GetData())>monthThis) {
                    expense.setDate(dateFunctions.dateStringToInt(xmlFile.GetData()));
                    expense.setUserLogin(userLoginLoggedIn);
                    xmlFile.FindElem("AMOUNT");
                    expense.setAmount(conversion.stringToDouble(xmlFile.GetData()));
                    xmlFile.FindElem("NAME");
                    expense.setName(xmlFile.GetData());
                    downloadedExpenses.push_back(expense);
                }
                xmlFile.OutOfElem();
            }
        }
    }
    return downloadedExpenses;
}
vector<Expense> FileExpense::getExpenseLastMonth() {
    Date dateFunctions;
    PresentDate presentDate;
    Conversion conversion;

    int monthLast = presentDate.getYearPresent()*10000+(presentDate.getMonthPresent()-1)*100;
    int monthThis = presentDate.getYearPresent()*10000+presentDate.getMonthPresent()*100;

    CMarkup xmlFile;
    if(xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("EXPENSES");
        xmlFile.IntoElem();
        if(xmlFile.FindElem(userLoginLoggedIn)) {
            xmlFile.IntoElem();
            xmlFile.ResetMainPos();

            for (int i=0; i<numberOfEntries; i++) {
                xmlFile.FindElem("ENTRY");
                xmlFile.IntoElem();
                xmlFile.FindElem("DATE");
                if((dateFunctions.dateStringToInt(xmlFile.GetData())>monthLast)&&(dateFunctions.dateStringToInt(xmlFile.GetData())<monthThis)) {
                    expense.setDate(dateFunctions.dateStringToInt(xmlFile.GetData()));
                    expense.setUserLogin(userLoginLoggedIn);
                    xmlFile.FindElem("AMOUNT");
                    expense.setAmount(conversion.stringToDouble(xmlFile.GetData()));
                    xmlFile.FindElem("NAME");
                    expense.setName(xmlFile.GetData());
                    downloadedExpenses.push_back(expense);
                }
                xmlFile.OutOfElem();
            }
        }
    }
    return downloadedExpenses;
}
vector<Expense> FileExpense::getExpenseChoosenDate(int firstDate, int secondDate) {
    Date dateFunctions;
    Conversion conversion;

    CMarkup xmlFile;
    if(xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("EXPENSES");
        xmlFile.IntoElem();
        if(xmlFile.FindElem(userLoginLoggedIn)) {
            xmlFile.IntoElem();
            xmlFile.ResetMainPos();

            for (int i=0; i<numberOfEntries; i++) {
                xmlFile.FindElem("ENTRY");
                xmlFile.IntoElem();
                xmlFile.FindElem("DATE");
                if((dateFunctions.dateStringToInt(xmlFile.GetData())>=firstDate)&&(dateFunctions.dateStringToInt(xmlFile.GetData())<=secondDate)) {
                    expense.setDate(dateFunctions.dateStringToInt(xmlFile.GetData()));
                    expense.setUserLogin(userLoginLoggedIn);
                    xmlFile.FindElem("AMOUNT");
                    expense.setAmount(conversion.stringToDouble(xmlFile.GetData()));
                    xmlFile.FindElem("NAME");
                    expense.setName(xmlFile.GetData());
                    downloadedExpenses.push_back(expense);
                }
                xmlFile.OutOfElem();
            }
        }
    }
    return downloadedExpenses;
}
void FileExpense::addExpense() {
    Date dateFunctions;
    Conversion conversion;

    CMarkup xmlFile;
    if(xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("EXPENSES");
        xmlFile.IntoElem();
        if(xmlFile.FindElem(userLoginLoggedIn)) {
            numberOfEntries++;
            xmlFile.SetAttrib("numberOfEntries", numberOfEntries);
            xmlFile.IntoElem();
            xmlFile.AddElem("ENTRY");
            xmlFile.IntoElem();
            xmlFile.AddElem("DATE", dateFunctions.dateIntToString(expense.getDate()));
            xmlFile.AddElem("AMOUNT", conversion.doubleToString(expense.getAmount()));
            xmlFile.AddElem("NAME", expense.getName());
            xmlFile.Save(nameFile.c_str());
        }
    }
}
void FileExpense::setNumberEntriesIfNeeded() {
    CMarkup xmlFile;
    if(xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("EXPENSES");
        xmlFile.IntoElem();
        if(xmlFile.FindElem(userLoginLoggedIn)) {
            this->numberOfEntries = atoi(MCD_2PCSZ(xmlFile.GetAttrib("numberOfEntries")));
        } else {
            xmlFile.AddElem(userLoginLoggedIn);
            xmlFile.SetAttrib("numberOfEntries","0");
            this->numberOfEntries = atoi(MCD_2PCSZ(xmlFile.GetAttrib("numberOfEntries")));
            xmlFile.Save(nameFile.c_str());
        }
    }
}
void FileExpense::setUserLoginLoggedIn(string userLoginLoggedIn) {
    this->userLoginLoggedIn = userLoginLoggedIn;
}

string FileExpense::getUserLoginLoggedIn() {
    return userLoginLoggedIn;
}

int FileExpense::getNumberOfEntries() {
    return numberOfEntries;
}
