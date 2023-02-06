#ifndef CLIONPROJECTS_BIGDECIMALINT_H
#define CLIONPROJECTS_BIGDECIMALINT_H

#include <iostream>
#include <string>
#include <regex>
using namespace std;

class BigDecimalInt {
    public:
        // Constructors
        BigDecimalInt() = default;
        BigDecimalInt(const int&);
        BigDecimalInt(const long long&);
        BigDecimalInt(string);

        // Getters
        int size ()const; // return # of digits
        bool isNegative()const;
        bool isPositive()const;


        //Assignment Operators
        BigDecimalInt& operator=(const BigDecimalInt&);
        BigDecimalInt& operator=(const long long&);
        BigDecimalInt& operator=(const string&);

        // Increment & Decrement Operators
        BigDecimalInt& operator++();       // pre-increment
        BigDecimalInt& operator--();       // pre-decrement
        BigDecimalInt operator++(int)const;     // post-increment
        BigDecimalInt operator--(int)const;     // post-decrement

        // Binary arithmetic Operators:
        BigDecimalInt operator+(const BigDecimalInt& )const ;
        BigDecimalInt operator+(const BigDecimalInt&& )const ;
        BigDecimalInt operator-(const BigDecimalInt&) const;
        BigDecimalInt operator-(const BigDecimalInt&& )const;
//        BigDecimalInt operator*(const BigDecimalInt&) const;
//        BigDecimalInt operator/(const BigDecimalInt&) const;
//        BigDecimalInt operator%(const BigDecimalInt&) const;


        // Arithmetic-assignment Operators
        BigDecimalInt& operator+=(const BigDecimalInt&);
        BigDecimalInt& operator-=(const BigDecimalInt&);
//        BigDecimalInt& operator*=(const BigDecimalInt&);
//        BigDecimalInt& operator/=(const BigDecimalInt&);
//        BigDecimalInt& operator%=(const BigDecimalInt&);


        // Comparison operators
        bool operator>(const BigDecimalInt& )const;
        bool operator>=(const BigDecimalInt& )const;
        bool operator<(const BigDecimalInt& )const;
        bool operator<=(const BigDecimalInt& )const;
        bool operator==(const BigDecimalInt& ) const;
        bool operator!=(const BigDecimalInt& ) const;


        // Conversion functions:
//        string to_string() const;
//        int to_int() const;
//        long long to_long_long() const;

//        **Note**: If the `BigDecimalInt` is beyond the range of the target type, an
//        [out_of_range exception][out_of_range-exception] is thrown.


        // I/O stream Operators
        friend istream& operator>>(istream&, BigDecimalInt&);
        friend ostream& operator<<(ostream&, const BigDecimalInt&);

    private:
        string digits = "0";
        char Sign = '+';

        // Helper Functions
        int getDigit(int) const;
        string performAddition(const BigDecimalInt& ,const BigDecimalInt&) const;
        string performSubtraction(const BigDecimalInt& , const BigDecimalInt& ) const;
        BigDecimalInt ninesComplement(int) const; // return 9's complement of the number
};



#endif //CLIONPROJECTS_BIGDECIMALINT_H
