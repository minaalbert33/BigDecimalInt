#ifndef CLIONPROJECTS_BIGDECIMALINT_H
#define CLIONPROJECTS_BIGDECIMALINT_H

#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt {
    public:
        // Constructors
        BigDecimalInt() = default;
        BigDecimalInt(const int&);
        BigDecimalInt(const long long&);
        BigDecimalInt(string);

        // Getters
        char sign ()const;
        int size ()const; // return # of digits
        bool isNegative()const;
        bool isPositive()const;


        // Overloaded operators
        friend ostream& operator<<(ostream&,const BigDecimalInt&);
        bool operator==(const BigDecimalInt& rhs) const;
        bool operator>(const BigDecimalInt& rhs)const;
        bool operator<(const BigDecimalInt& rhs)const;
        BigDecimalInt operator+(BigDecimalInt& rhs);
        BigDecimalInt operator-(BigDecimalInt& rhs);


    private:
        string digits = "0";
        char Sign = '+';

        // Helper Functions
        int getDigit(int) const;
        string performAddition(const BigDecimalInt& ,const BigDecimalInt&) const;
        string perform_subtraction(const BigDecimalInt& , const BigDecimalInt& ) const;
        // return 9's complement of the number
        BigDecimalInt ninesComplement(int) const;
};



#endif //CLIONPROJECTS_BIGDECIMALINT_H
