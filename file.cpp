#include <iostream>
#include "file.h"

using namespace std;

void File::creatUserFileIfNeeded() {
    CMarkup xmlFile;
    if(!xmlFile.Load(nameFile.c_str())){
        xmlFile.AddElem("USERS");
        xmlFile.SetAttrib("numberOfUsers", "0");
        xmlFile.Save(nameFile.c_str());
    }
}
void File::creatIncomeFileIfNeeded(){
    CMarkup xmlFile;
    if(!xmlFile.Load(nameFile.c_str())){
        xmlFile.AddElem("INCOMINGS");
        xmlFile.Save(nameFile.c_str());
    }
}
void File::creatExpenseFileIfNeeded(){
    CMarkup xmlFile;
    if(!xmlFile.Load(nameFile.c_str())){
        xmlFile.AddElem("EXPENSES");
        xmlFile.Save(nameFile.c_str());
    }
}
