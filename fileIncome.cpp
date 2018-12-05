#include <iostream>
#include "fileIncome.h"

using namespace std;

FileIncome::FileIncome(string nameFile) {
    this->nameFile = nameFile;
}
void FileIncome::clearVector() {
    downloadedIncomings.clear();
}
vector<Income> FileIncome::getIncomeThisMonth() {
    Date dateFunctions;
    PresentDate presentDate;
    Conversion conversion;

    int monthThis = presentDate.getYearPresent()*10000+presentDate.getMonthPresent()*100;

    CMarkup xmlFile;
    if(xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("INCOMINGS");
        xmlFile.IntoElem();
        if(xmlFile.FindElem(userLoginLoggedIn)) {
            xmlFile.IntoElem();
            xmlFile.ResetMainPos();

            for (int i=0; i<numberOfEntries; i++) {
                xmlFile.FindElem("ENTRY");
                xmlFile.IntoElem();
                xmlFile.FindElem("DATE");
                if(dateFunctions.dateStringToInt(xmlFile.GetData())>monthThis) {
                    income.setDate(dateFunctions.dateStringToInt(xmlFile.GetData()));
                    income.setUserLogin(userLoginLoggedIn);
                    xmlFile.FindElem("AMOUNT");
                    income.setAmount(conversion.stringToDouble(xmlFile.GetData()));
                    xmlFile.FindElem("NAME");
                    income.setName(xmlFile.GetData());
                    downloadedIncomings.push_back(income);
                }
                xmlFile.OutOfElem();
            }
        }
    }
    return downloadedIncomings;
}
vector<Income> FileIncome::getIncomeLastMonth() {
    Date dateFunctions;
    PresentDate presentDate;
    Conversion conversion;

    int monthLast = presentDate.getYearPresent()*10000+(presentDate.getMonthPresent()-1)*100;
    int monthThis = presentDate.getYearPresent()*10000+presentDate.getMonthPresent()*100;

    CMarkup xmlFile;
    if(xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("INCOMINGS");
        xmlFile.IntoElem();
        if(xmlFile.FindElem(userLoginLoggedIn)) {
            xmlFile.IntoElem();
            xmlFile.ResetMainPos();

            for (int i=0; i<numberOfEntries; i++) {
                xmlFile.FindElem("ENTRY");
                xmlFile.IntoElem();
                xmlFile.FindElem("DATE");
                if((dateFunctions.dateStringToInt(xmlFile.GetData())>monthLast)&&(dateFunctions.dateStringToInt(xmlFile.GetData())<monthThis)) {
                    income.setDate(dateFunctions.dateStringToInt(xmlFile.GetData()));
                    income.setUserLogin(userLoginLoggedIn);
                    xmlFile.FindElem("AMOUNT");
                    income.setAmount(conversion.stringToDouble(xmlFile.GetData()));
                    xmlFile.FindElem("NAME");
                    income.setName(xmlFile.GetData());
                    downloadedIncomings.push_back(income);
                }
                xmlFile.OutOfElem();
            }
        }
    }
    return downloadedIncomings;
}
vector<Income> FileIncome::getIncomeChoosenDate(int firstDate, int secondDate) {
    Date dateFunctions;
    Conversion conversion;

    CMarkup xmlFile;
    if(xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("INCOMINGS");
        xmlFile.IntoElem();
        if(xmlFile.FindElem(userLoginLoggedIn)) {
            xmlFile.IntoElem();
            xmlFile.ResetMainPos();

            for (int i=0; i<numberOfEntries; i++) {
                xmlFile.FindElem("ENTRY");
                xmlFile.IntoElem();
                xmlFile.FindElem("DATE");
                if((dateFunctions.dateStringToInt(xmlFile.GetData())>=firstDate)&&(dateFunctions.dateStringToInt(xmlFile.GetData())<=secondDate)) {
                    income.setDate(dateFunctions.dateStringToInt(xmlFile.GetData()));
                    income.setUserLogin(userLoginLoggedIn);
                    xmlFile.FindElem("AMOUNT");
                    income.setAmount(conversion.stringToDouble(xmlFile.GetData()));
                    xmlFile.FindElem("NAME");
                    income.setName(xmlFile.GetData());
                    downloadedIncomings.push_back(income);
                }
                xmlFile.OutOfElem();
            }
        }
    }
    return downloadedIncomings;
}
void FileIncome::addIncome() {
    Date dateFunctions;
    Conversion conversion;

    CMarkup xmlFile;
    if(xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("INCOMINGS");
        xmlFile.IntoElem();
        if(xmlFile.FindElem(userLoginLoggedIn)) {
            numberOfEntries++;
            xmlFile.SetAttrib("numberOfEntries", numberOfEntries);
            xmlFile.IntoElem();
            xmlFile.AddElem("ENTRY");
            xmlFile.IntoElem();
            xmlFile.AddElem("DATE", dateFunctions.dateIntToString(income.getDate()));
            xmlFile.AddElem("AMOUNT", conversion.doubleToString(income.getAmount()));
            xmlFile.AddElem("NAME", income.getName());
            xmlFile.Save(nameFile.c_str());
        }
    }
}
void FileIncome::setNumberEntriesIfNeeded() {
    CMarkup xmlFile;
    if(xmlFile.Load(nameFile.c_str())) {
        xmlFile.FindElem("INCOMINGS");
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
void FileIncome::setUserLoginLoggedIn(string userLoginLoggedIn) {
    this->userLoginLoggedIn = userLoginLoggedIn;
}

string FileIncome::getUserLoginLoggedIn() {
    return userLoginLoggedIn;
}

int FileIncome::getNumberOfEntries() {
    return numberOfEntries;
}
