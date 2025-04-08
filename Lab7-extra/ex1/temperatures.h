#pragma once

float operator"" _Kelvin(long double value) {
    return static_cast<float>(value - 273.15);
}

float operator"" _Fahrenheit(long double value) {
    return static_cast<float>((value - 32.0) * 5.0 / 9.0);
}

float operator"" _Kelvin(unsigned long long int value) {
    return static_cast<float>(value - 273.15);
}

float operator"" _Fahrenheit(unsigned long long int value) {
    return static_cast<float>((value - 32.0) * 5.0 / 9.0);
}