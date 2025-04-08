#include "Number.h"
#include <cstring>
#include <iostream>
#include <stdexcept>

Number::Number(const char *value, int given_base)
{
    base = given_base;
    val = new char[strlen(value) + 1];
    memcpy(val, value, strlen(value));
    val[strlen(value)] = 0;
}

Number::Number(const int nr)
{
    base = 10;
    int nr_digits = 0, copy = nr;

    if (nr == 0)
    {
        val = new char[2];
        val[0] = '0';
        val[1] = 0;
        return;
    }

    while (copy)
    {
        nr_digits++;
        copy /= 10;
    }

    copy = nr;
    val = new char[nr_digits + 1];
    val[nr_digits] = '\0';
    for (int ind = nr_digits - 1; ind >= 0; ind--)
    {
        val[ind] = '0' + copy % 10;
        copy /= 10;
    }
}

Number::Number(const char *nr)
{
    base = 10;
    val = new char[strlen(nr) + 1];
    memcpy(val, nr, strlen(nr));
    val[strlen(nr)] = 0;
}

Number::Number(const Number &other)
{
    base = other.base;
    val = new char[strlen(other.val) + 1];
    memcpy(val, other.val, strlen(other.val));
    val[strlen(other.val)] = 0;
}

Number::Number(Number &&other)
{
    base = other.base;
    val = other.val;
    other.val = nullptr;
}

Number::~Number()
{
    if (val != nullptr)
    {
        delete [] val;
    }
}

void Number::operator=(const Number &other)
{
    if (this != &other)
    {
        if (val != nullptr)
        {
            delete[] val;
        }
        base = other.base;
        val = new char[strlen(other.val) + 1];
        memcpy(val, other.val, strlen(other.val));
    }
}

char &Number::operator[](const int index)
{
    return val[index];
}

bool operator<(const Number &nr1, const Number &nr2)
{
    return strcmp(nr1.val, nr2.val) < 0;
}

bool operator>(const Number &nr1, const Number &nr2)
{
    return strcmp(nr1.val, nr2.val) > 0;
}

bool operator<=(const Number &nr1, const Number &nr2)
{
    return strcmp(nr1.val, nr2.val) <= 0;
}

bool operator>=(const Number &nr1, const Number &nr2)
{
    return strcmp(nr1.val, nr2.val) >= 0;
}

bool operator==(const Number &nr1, const Number &nr2)
{
    return strcmp(nr1.val, nr2.val) == 0;
}

Number operator+(const Number &nr1, const Number &nr2)
{
    Number temp1 = nr1, temp2 = nr2;
    if (nr1.base != nr2.base)
    {
        if (nr1.base > nr2.base)
            temp2.SwitchBase(nr1.base);
        else
            temp1.SwitchBase(nr2.base);
    }
    return AddSameBase(temp1, temp2);
}

Number operator-(const Number &nr1, const Number &nr2)
{
    Number temp1 = nr1, temp2 = nr2;
    if (nr1.base != nr2.base)
    {
        if (nr1.base > nr2.base)
            temp2.SwitchBase(nr1.base);
        else
            temp1.SwitchBase(nr2.base);
    }
    return SubSameBase(temp1, temp2);
}

void Number::operator+=(const Number &nr)
{
    *this = *this + nr;
}

void Number::operator-=(const Number &nr)
{
    *this = *this - nr;
}

void Number::SwitchBase(int newBase)
{
    int decimal = 0, len = strlen(val), digit;
    for (int i = 0; i < len; ++i)
    {
        digit = (val[i] >= 'A') ? (val[i] - 'A' + 10) : (val[i] - '0');
        decimal = decimal * base + digit;
    }

    if (decimal == 0)
    {
        delete[] val;
        val = new char[2];
        val[0] = '0';
        val[1] = 0;
    }
    else
    {
        int tempval = decimal, nrdigits = 0, index, remainder;
        while (tempval > 0)
        {
            tempval /= newBase;
            nrdigits++;
        }

        delete[] val;
        val = new char[nrdigits + 1];
        val[nrdigits] = '\0';

        index = nrdigits - 1;
        while (decimal > 0)
        {
            remainder = decimal % newBase;
            decimal /= newBase;
            val[index--] = (remainder >= 10) ? ('A' + (remainder - 10)) : ('0' + remainder);
        }
    }
    base = newBase;
}

void Number::Print()
{
    std::cout << "Value: " << val << "\nBase: " << base << std::endl;
}

int Number::GetDigitsCount()
{
    return strlen(val);
}

int Number::GetBase()
{
    return base;
}

Number Number::operator++()
{
    Number one("1", base);
    *this = *this + one;
    return *this;
}

Number Number::operator++(int)
{
    Number temp = *this;
    ++(*this);
    return temp;
}

void Number::operator--()
{
    if (strlen(val) > 1)
        memcpy(val, val + 1, strlen(val)-1);
    else
    {
        delete[] val;
        val = new char[2];
        val[0] = '0';
        val[1] = 0;
    }
}

void Number::operator--(int)
{
    if (strlen(val) > 1)
        val[strlen(val) - 1] = '\0';
    else
    {
        delete[] val;
        val = new char[2];
        val[0] = '0';
        val[1] = 0;
    }
}

Number AddSameBase(const Number& nr1, const Number& nr2)
{
    if (nr1.val == nullptr || nr2.val == nullptr) {
        printf("Error: One of the Number objects has an uninitialized val pointer.\n");
        exit(1);
    }

    int base = nr1.base, len1 = strlen(nr1.val), len2 = strlen(nr2.val);
    int maxlen = (len1 > len2) ? len1 : len2;

    char* resultval = new char[maxlen + 2];
    resultval[maxlen + 1] = '\0';

    int carry = 0, i = len1 - 1, j = len2 - 1, k = maxlen;
    int digit1, digit2, sum;

    while (i >= 0 || j >= 0 || carry) {
        digit1 = (i >= 0) ? (nr1.val[i] >= 'A' ? nr1.val[i] - 'A' + 10 : nr1.val[i] - '0') : 0;
        digit2 = (j >= 0) ? (nr2.val[j] >= 'A' ? nr2.val[j] - 'A' + 10 : nr2.val[j] - '0') : 0;
        
        sum = digit1 + digit2 + carry;
        carry = sum / base;
        sum %= base;
        
        resultval[k--] = (sum >= 10) ? ('A' + (sum - 10)) : ('0' + sum);
        
        i--;
        j--;
    }
    
    Number result;
    result.val = new char[strlen(resultval + k + 1) + 1];
    strcpy(result.val, resultval + k + 1);
    result.base = base;
    
    delete[] resultval;
    return result;
}

Number SubSameBase(const Number& nr1, const Number& nr2)
{
    if (nr1.val == nullptr || nr2.val == nullptr) {
        printf("Error: One of the Number objects has an uninitialized val pointer.\n");
        exit(1);
    }

    int base = nr1.base, len1 = strlen(nr1.val), len2 = strlen(nr2.val);
    
    if (len1 < len2 || (len1 == len2 && strcmp(nr1.val, nr2.val) < 0)) {
        printf("Subtraction would result in a negative number, which is not supported.");
        exit(1);
    }
    
    if (strcmp(nr1.val, nr2.val) == 0)
    {
        Number result("0", nr1.base);
        return result;
    }
    
    char* resultVal = new char[len1 + 1];
    resultVal[len1] = '\0';
    
    int borrow = 0, i = len1 - 1, j = len2 - 1, k = len1 - 1;
    int digit1, digit2, diff;
    
    while (i >= 0) {
        digit1 = (nr1.val[i] >= 'A') ? (nr1.val[i] - 'A' + 10) : (nr1.val[i] - '0');
        digit2 = (j >= 0) ? ((nr2.val[j] >= 'A') ? (nr2.val[j] - 'A' + 10) : (nr2.val[j] - '0')) : 0;
        
        digit1 -= borrow;
        if (digit1 < digit2) {
            digit1 += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        diff = digit1 - digit2;
        resultVal[k--] = (diff >= 10) ? ('A' + (diff - 10)) : ('0' + diff);
        
        i--;
        j--;
    }
    
    char* finalResult = resultVal;
    while (*finalResult == '0' && *(finalResult + 1) != '\0') {
        finalResult++;
    }
    
    Number result;
    result.val = new char[strlen(finalResult) + 1];
    strcpy(result.val, finalResult);
    result.base = base;
    
    delete[] resultVal;
    return result;
}