#include "BigDecimalInt.h"

BigDecimalInt::BigDecimalInt(string decStr){

    regex validNumber("^[+-]?[0-9]+$");
    if (!regex_match(decStr, validNumber))
        throw "Invalid Number, found characters except digits and '-', '+' ";

    bool signExist = (decStr[0] == '-' || decStr[0] == '+');

    // if number is all zeroes we will start erasing from position 1 e.g. (000000)
    regex allZeroes("^[0]+$");
    if (regex_match(decStr, allZeroes))
        signExist = true;

    // Removing Trailing Zeroes e.g. (000187)
    int lengthToRemove = signExist;
    while (decStr[lengthToRemove] == '0'){
        lengthToRemove++;
    }
    decStr.erase(signExist, lengthToRemove - signExist);

    // Seperating the minusOrPlus from the digits
    if (decStr[0] == '-'){
        Sign = '-';
        digits = decStr.substr(1, decStr.size() - 1);
    }else if (decStr[0] == '+'){
        Sign = '+';
        digits = decStr.substr(1, decStr.size() - 1);
    }else{
        Sign = '+';
        digits = decStr;
    }
}

BigDecimalInt::BigDecimalInt(const int& x) :
    BigDecimalInt(to_string(x)) {}

BigDecimalInt::BigDecimalInt(const long long& x) :
        BigDecimalInt(to_string(x)) {}

char BigDecimalInt::sign() const{
    return Sign;
}

int BigDecimalInt::size() const{
    return digits.size();
}

ostream &operator<<(ostream &out, const BigDecimalInt &num){
    // print number with '-' sign or without '+' sign
    if (num.Sign == '-')
        out << num.Sign << num.digits;
    else
        out << num.digits;
    return out;
}

bool BigDecimalInt::operator==(const BigDecimalInt &rhs) const{
    // checking if two objects has the same minusOrPlus, then checking the digits
    if (this->Sign == rhs.Sign)
        return (this->digits == rhs.digits);
    else
        return false;
}

bool BigDecimalInt::isNegative() const{
    return (Sign == '-');
}

bool BigDecimalInt::isPositive() const{
    return (Sign == '+');
}

int BigDecimalInt::getDigit(int index) const{
    if (index >= 0 && index < this->digits.size())
        return this->digits[index] - '0';

    // return 0 if index not in the size of digits
    return 0;
}

bool BigDecimalInt::operator<(const BigDecimalInt &rhs) const{
    if (this->isNegative() != rhs.isNegative())
        return (this->isNegative());

    if (this->size() != rhs.size()){
        if (this->size() > rhs.size() && this->isPositive())
            return false;
        else if (this->size() < rhs.size() && this->isNegative())
            return false;
        else
            return true;
    }

    for (int i = 0; i < this->size(); i++){
        if (this->digits[i] > rhs.digits[i])
            return this->isNegative();
        else if (this->digits[i] < rhs.digits[i])
            return this->isPositive();
    }
    return false;
}

bool BigDecimalInt::operator>(const BigDecimalInt &rhs) const{
    // Signs aren't the same, *this > rhs only if *this is positive
    if (this->isNegative() != rhs.isNegative())
        return (this->isPositive());

    // Digits aren't the same, then check # of digits and minusOrPlus

    // Case 1: e.g. (-13, -123)
    bool case1 = (this->size() < rhs.size()) && this->isNegative();
    // Case 2: e.g. (555, 5)
    bool case2 = (this->size() > rhs.size()) && this->isPositive();
    if (this->size() != rhs.size())
        return (case1 || case2);

    // Signs are the same, # of digits is same
    for (int i = 0; i < rhs.size(); i++){
        if (this->digits[i] < rhs.digits[i])
            return this->isNegative();
        if (this->digits[i] > rhs.digits[i])
            return this->isPositive();
    }
    return false; // *this == rhs
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt &rhs){
    string s;
    BigDecimalInt temp, zero("0");
    if (this->isPositive() && rhs.isPositive())
        s = performAddition(*this, rhs);

    // both numbers are negative e.g. (-3 + (-7)) -> -(3 + 7)
    else if (this->isNegative() && rhs.isNegative()){
        s = performAddition(*this, rhs);
        s.insert(0, 1, '-');
    }
    // e.g. (-3 + 7) -> (7 - 3)
    else if (this->isNegative() && rhs.isPositive()){
        temp = zero - *this;
        if (rhs < temp)
        {
            s = perform_subtraction(temp, rhs);
            s.insert(0, 1, '-');
        }
        else if (rhs > temp || temp == rhs)
        {
            s = perform_subtraction(rhs, temp);
        }
    }
    // e.g. (3 + (-7)) -> (3 - 7)
    else if (this->isPositive() && rhs.isNegative()){

        temp = zero - rhs;
        if (*this > temp || *this == temp){
            s = perform_subtraction(*this, temp);
        }else if (*this < temp){
            s = perform_subtraction(temp, *this);
            s.insert(0, 1, '-');
        }
    }
    return BigDecimalInt(s);
}

BigDecimalInt BigDecimalInt::ninesComplement(int len) const{
    string result = "";
    int sizeDifference = len - this->size();
    // Subtract each digit from 9
    for (int i = len - 1; i >= 0; i--){
        if (i >= sizeDifference)
            result += char(9 - (this->digits[i - sizeDifference] - '0') + '0');
        else
            result += char(9 + '0');
    }

    reverse(result.begin(), result.end());
    return BigDecimalInt(result);
}

string BigDecimalInt::performAddition(const BigDecimalInt &num1, const BigDecimalInt &num2) const{
    string result = "";
    int sum, len, size_diff;
    // Storing the bigger size between num1 and num2
    len = (num1.size() > num2.size()) ? num1.size() : num2.size();
    // Calculate the differnce in size of num1, num2
    size_diff = abs(int(num1.size() - num2.size()));

    bool carry = false, is_num1_longer = (num1.size() > num2.size());
    for (int i = len - 1; i >= 0; i--){
        if (is_num1_longer)
            sum = num1.getDigit(i) + num2.getDigit(i - size_diff) + carry;
        else
            sum = num1.getDigit(i - size_diff) + num2.getDigit(i) + carry;

        carry = (sum > 9);
        sum %= 10;
        result += char(sum + '0');
    }
    if (carry != 0)
        result += char(carry + '0');

    reverse(result.begin(), result.end());
    return result;
}

string BigDecimalInt::perform_subtraction(const BigDecimalInt &num1, const BigDecimalInt &num2) const{
    string result = "", gf = "";

    // Getting the bigger length between num1 and num2
    int lengthToLoop = (num1.size() > num2.size()) ? num1.size() : num2.size();

    // Getting 9's complement of num2 then add it to num1
    BigDecimalInt temp = num2.ninesComplement(lengthToLoop);
    result = performAddition(num1, temp);
    BigDecimalInt one("1"), l(result);
    gf = performAddition(l, one);
    // Removing the carry if exist
    if (gf.size() > lengthToLoop)
        gf.erase(0, 1);
    return gf;
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt &rhs){
    string s = "";
    // e.g. (3 -(-9)) -> 3 + 9
    if (this->isPositive() && rhs.isNegative()){
        s = performAddition(*this, rhs);
    }
    //  e.g. (-3 - (+9)) --> -(3 + 9)
    else if (this->isNegative() && rhs.isPositive()){
        s = performAddition(*this, rhs);
        s.insert(0, 1, '-');
    }
    // e.g. (9 - 3)
    else if (this->isPositive() && rhs.isPositive() && *this > rhs || *this == rhs){
        s = perform_subtraction(*this, rhs);
    }
    // e.g. 15 - 18 --> -(18 - 15)
    else if (this->isPositive() && rhs.isPositive() && *this < rhs){
        s = perform_subtraction(rhs, *this);
        s.insert(0, 1, '-');
    }
    // e.g. -19 -(-3) -> -(19 - 3)
    else if (this->isNegative() && rhs.isNegative() && *this < rhs){
        s = perform_subtraction(*this, rhs);
        s.insert(0, 1, '-');
    }
    // e.g. -2 -(-19) -> (-2 + 19) -> (19 - 2)
    else if (this->isNegative() && rhs.isNegative() && *this > rhs || *this == rhs){
        s = perform_subtraction(rhs, *this);
    }
    
    return BigDecimalInt(s);
}
