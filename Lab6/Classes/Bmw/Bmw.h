#include "../Car.h"
#pragma once
class Bmw:public Car
{
public:
    Bmw(char* given_name);
    ~Bmw();
    float GetFuelCapacity();
    float GetFuelConsumption();
    float GetAvgSpeed(Weather);
    char* GetName();
};