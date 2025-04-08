#include "Volvo.h"
#include <stdio.h>
#include <string.h>
#include "../Weather.h"

Volvo::Volvo(char* given_name)
{
    maxfuel = 150.f;
    consumption = 15.4f;
    avg_speed[0] = 83.5f;
    avg_speed[1] = 99.2f;
    avg_speed[2] = 55.1f;
    name = new char[strlen(given_name)+1];
    memcpy(name, given_name, strlen(given_name)+1);
}

Volvo::~Volvo()
{
    delete [] name;
}

float Volvo::GetFuelCapacity()
{
    return maxfuel;
}

float Volvo::GetFuelConsumption()
{
    return consumption;
}

float Volvo::GetAvgSpeed(Weather condition)
{
    return avg_speed[condition];
}

char* Volvo::GetName()
{
    return name;
}