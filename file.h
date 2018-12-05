#include <iostream>
#include <windows.h>
#include "Markup.h"
#pragma once
using namespace std;

class File{
protected:
    string nameFile;
public:
    void creatUserFileIfNeeded();
    void creatIncomeFileIfNeeded();
    void creatExpenseFileIfNeeded();
};
