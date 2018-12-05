#include <iostream>
#include "expense.h"

using namespace std;

void Expense::setDate(int date){
    this->date = date;
}
void Expense::setName(string name){
    this->name = name;
}
void Expense::setAmount(double amount){
    this->amount = amount;
}
void Expense::setUserLogin(string userLoginLoggedIn){
    this->userLoginLoggedIn = userLoginLoggedIn;
}

int Expense::getDate(){
    return date;
}
string Expense::getName(){
    return name;
}
double Expense::getAmount(){
    return amount;
}
string Expense::getUserLogin(){
    return userLoginLoggedIn;
}

 bool Expense::operator<(Expense second){
    return this->date < second.getDate();
}
