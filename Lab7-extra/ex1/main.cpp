#include "temperatures.h"
#include <stdio.h>

int main()
{
    float a = 300.1_Kelvin;
    float b = 120.3_Fahrenheit;

    float c = 300_Kelvin;
    float d = 119_Fahrenheit;
    printf("%f %f %f %f", a, b, c, d);
    return 0;
}