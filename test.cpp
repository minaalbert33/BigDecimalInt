#include<iostream>
#include "BigDecimalInt.h"
using namespace std;

int main (){
    BigDecimalInt a("3"), b("-000000011");
    a-=00;
    cout << "a: " << a << ' ' << "b: " << b << endl;
//    cout << ++a;
}