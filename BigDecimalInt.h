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


        //Assignment Operators
        BigDecimalInt& operator=(const BigDecimalInt&);
        BigDecimalInt& operator=(const long long&);
        BigDecimalInt& operator=(const string&);

        // Increment and decrement operators
        BigDecimalInt& operator++();       // pre-increment
        BigDecimalInt& operator--();       // pre-decrement
        BigDecimalInt operator++(int);     // post-increment
        BigDecimalInt operator--(int);     // post-decrement

        // Binary arithmetic operators:
        BigDecimalInt operator+(const BigDecimalInt& )const ;
        BigDecimalInt operator-(const BigDecimalInt&) const;
//        BigDecimalInt operator*(const BigDecimalInt&) const;
//        BigDecimalInt operator/(const BigDecimalInt&) const;
//        BigDecimalInt operator%(const BigDecimalInt&) const;
        BigDecimalInt operator+(const long long&) const;
        BigDecimalInt operator-(const long long&) const;
//        BigDecimalInt operator*(const long long&) const;
//        BigDecimalInt operator/(const long long&) const;
//        BigDecimalInt operator%(const long long&) const;
        BigDecimalInt operator+(const string&) const;
        BigDecimalInt operator-(const string&) const;
//        BigDecimalInt operator*(const string&) const;
//        BigDecimalInt operator/(const string&) const;
//        BigDecimalInt operator%(const string&) const;

        // Arithmetic-assignment operators
        BigDecimalInt& operator+=(const BigDecimalInt&);
        BigDecimalInt& operator-=(const BigDecimalInt&);
//        BigDecimalInt& operator*=(const BigDecimalInt&);
//        BigDecimalInt& operator/=(const BigDecimalInt&);
//        BigDecimalInt& operator%=(const BigDecimalInt&);
        BigDecimalInt& operator+=(const long long&);
        BigDecimalInt& operator-=(const long long&);
//        BigDecimalInt& operator*=(const long long&);
//        BigDecimalInt& operator/=(const long long&);
//        BigDecimalInt& operator%=(const long long&);
        BigDecimalInt& operator+=(const string&);
        BigDecimalInt& operator-=(const string&);
//        BigDecimalInt& operator*=(const std::string&);
//        BigDecimalInt& operator/=(const std::string&);
//        BigDecimalInt& operator%=(const std::string&);

        // I/O stream operators
        friend istream& operator>>(istream&, BigDecimalInt&);
        friend ostream& operator<<(ostream&, const BigDecimalInt&);


        // Overloaded operators
        friend ostream& operator<<(ostream&,const BigDecimalInt&);
        bool operator==(const BigDecimalInt& ) const;
        bool operator>(const BigDecimalInt& )const;
        bool operator<(const BigDecimalInt& )const;

        BigDecimalInt operator+(const BigDecimalInt&& )const ;
        BigDecimalInt operator-(const BigDecimalInt&& )const ;


    private:
        string digits = "0";
        char Sign = '+';

        // Helper Functions
        int getDigit(int) const;
        string performAddition(const BigDecimalInt& ,const BigDecimalInt&) const;
        string perform_subtraction(const BigDecimalInt& , const BigDecimalInt& ) const;
        BigDecimalInt ninesComplement(int) const; // return 9's complement of the number
};



#endif //CLIONPROJECTS_BIGDECIMALINT_H
