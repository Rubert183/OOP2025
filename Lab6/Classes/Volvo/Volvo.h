#include "../Car.h"
#pragma once
class Volvo:public Car
{
public:
    Volvo(char* given_name);
    ~Volvo();
    float GetFuelCapacity();
    float GetFuelConsumption();
    float GetAvgSpeed(Weather);
    char* GetName();
};