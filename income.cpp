#include <iostream>
#include "income.h"

using namespace std;

void Income::setDate(int date){
    this->date = date;
}
void Income::setName(string name){
    this->name = name;
}
void Income::setAmount(double amount){
    this->amount = amount;
}
void Income::setUserLogin(string userLoginLoggedIn){
    this->userLoginLoggedIn = userLoginLoggedIn;
}

int Income::getDate(){
    return date;
}
string Income::getName(){
    return name;
}
double Income::getAmount(){
    return amount;
}
string Income::getUserLogin(){
    return userLoginLoggedIn;
}

 bool Income::operator<(Income second){
    return this->date < second.getDate();
}
