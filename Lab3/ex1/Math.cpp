#include "Math.h"
#include <iostream>
#include <stdarg.h>
#include <cstring>
int Math::Add(int nr1, int nr2)
{
    return nr1+nr2;
}
int Math::Add(int nr1, int nr2, int nr3)
{
    return nr1+nr2+nr3;
}
int Math::Add(double nr1, double nr2)
{
    return (int)(nr1+nr2);
}
int Math::Add(double nr1, double nr2, double nr3)
{
    return (int)(nr1+nr2+nr3);
}

int Math::Mul(int nr1, int nr2)
{
    return nr1*nr2;
}
int Math::Mul(int nr1, int nr2, int nr3)
{
    return nr1*nr2*nr3;
}
int Math::Mul(double nr1, double nr2)
{
    return (int)(nr1*nr2);
}
int Math::Mul(double nr1, double nr2, double nr3)
{
    return (int)(nr1*nr2*nr3);
}

int Math::Add(int count, ...)
{
    int sum = 0, nr;
    va_list vl;
    va_start(vl, count);
    for (int ind=0; ind < count; ind++)
    {
        nr = va_arg(vl, int);
        sum+=nr;
    }
    return sum;
}

char* Math::Add(const char *nr1, const char *nr2)
{
    if (nr1 == nullptr || nr2 == nullptr)
    {
        return nullptr;
    }

    char *nr3;
    int lim1 = strlen(nr1), lim2 = strlen(nr2), carry = 0, aux;
    int ind1 = lim1 - 1, ind2 = lim2 - 1, ind;

    if (lim1 > lim2)
    {
        nr3 = new char[lim1 + 2];
        ind = lim1 + 1;
    }
    else
    {
        nr3 = new char[lim2 + 2];
        ind = lim2 + 1;
    }
    
    nr3[ind] = '\0';
    ind--;

    while (ind1 >= 0 && ind2 >= 0)
    {
        aux = (nr1[ind1] - '0') + (nr2[ind2] - '0') + carry;
        nr3[ind--] = (aux % 10) + '0';
        carry = aux / 10;
        ind1--;
        ind2--;
    }
    while (ind1 >= 0)
    {
        aux = (nr1[ind1] - '0') + carry;
        nr3[ind--] = (aux % 10) + '0';
        carry = aux / 10;
        ind1--;
    }
    while (ind2 >= 0)
    {
        aux = (nr2[ind2] - '0') + carry;
        nr3[ind--] = (aux % 10) + '0';
        carry = aux / 10;
        ind2--;
    }
    if (carry)
    {
        nr3[ind] = carry + '0';
        return nr3;
    }
    else
    {
        return nr3 + 1; 
    }
}
