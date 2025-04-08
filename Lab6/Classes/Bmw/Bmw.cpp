#include "Bmw.h"
#include <stdio.h>
#include <string.h>
#include "../Weather.h"

Bmw::Bmw(char* given_name)
{
    maxfuel = 80.f;
    consumption = 15.f;
    avg_speed[0] = 120.f;
    avg_speed[1] = 180.f;
    avg_speed[2] = 60.f;
    name = new char[strlen(given_name)+1];
    memcpy(name, given_name, strlen(given_name)+1);
}

Bmw::~Bmw()
{
    delete [] name;
}

float Bmw::GetFuelCapacity()
{
    return maxfuel;
}

float Bmw::GetFuelConsumption()
{
    return consumption;
}

float Bmw::GetAvgSpeed(Weather condition)
{
    return avg_speed[condition];
}

char* Bmw::GetName()
{
    return name;
}