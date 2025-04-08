#pragma once
#include "Weather.h"
class Car
{
protected:
    float maxfuel, consumption, avg_speed[3];
    char* name;
public:
    virtual char* GetName() = 0;
    virtual float GetFuelCapacity() = 0;
    virtual float GetFuelConsumption() = 0;
    virtual float GetAvgSpeed(Weather) = 0;
};