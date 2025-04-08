#include "../Car.h"
#pragma once
class Opel: public Car
{
public:
    Opel(char* given_name);
    ~Opel();
    float GetFuelCapacity();
    float GetFuelConsumption();
    float GetAvgSpeed(Weather);
    char* GetName();
};