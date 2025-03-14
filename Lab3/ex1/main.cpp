#include "Math.h"
#include "Math.cpp"
#include <iostream>
int main()
{
    Math v;
    printf("1 + 3 = %d\n", v.Add(1, 3));
    printf("1 + 2 + 3 = %d\n", v.Add(1, 2, 3));
    printf("floor(1.1, 2.2) = %d\n", v.Add(1.1, 2.2));
    printf("floor(1.1, 2.2, 3.3) = %d\n", v.Add(1.1, 2.2, 3.3));
    printf("2 * 3 = %d\n", v.Mul(2, 3));
    printf("2 * 3 * 4 = %d\n", v.Mul(2, 3, 4));
    printf("floor(2.5, 3.6) = %d\n", v.Mul(2.5, 3.6));
    printf("floor(2.5, 3.6, 4.2) = %d\n", v.Mul(2.5, 3.6, 4.2));
    printf("1 + 2 + 3 + 4 + 5 + 6 = %d\n", v.Add(5, 1, 2, 3, 4, 5));
    printf("123456789123 + 123456789123 = %s\n", v.Add("123456789123", "123456789123"));
    printf("100 + 123 = %s", v.Add("123", "100"));
    return 0;
}