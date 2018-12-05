#include <iostream>
#include "amount.h"

using namespace std;

void Amount::changeCommaToDot(string& amount){
    int numberCharacters = amount.size();
    for(int i=0; i<numberCharacters; i++){
        if(amount[i]==','){
            amount[i]='.';
        }
    }
}
bool Amount::checkAmountDigit(string amount){
    int numberCharacters = amount.size();
    for (int i=0; i<numberCharacters; i++){
        if((int)amount[i]>=48&&(int)amount[i]<=57||(int)amount[i]==46){
            return true;
        }
    }
    return false;
}
bool Amount::checkAmountValue(double amount){
    if(amount<=0){
        return false;
    }
    return true;
}
