#include "../Car.h"
#pragma once
class Mazda:public Car
{
public:
    Mazda(char* given_name);
    ~Mazda();
    float GetFuelCapacity();
    float GetFuelConsumption();
    float GetAvgSpeed(Weather);
    char* GetName();
};