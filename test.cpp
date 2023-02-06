#include<iostream>
#include "BigDecimalInt.h"
using namespace std;

int main (){
    BigDecimalInt a("0000000000000004"), b("-4");
    cout << (a  + BigDecimalInt(0));
}