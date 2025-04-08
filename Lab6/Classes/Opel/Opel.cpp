#include "Opel.h"
#include <stdio.h>
#include <string.h>
#include "../Weather.h"

Opel::Opel(char* given_name)
{
    maxfuel = 120.f;
    consumption = 6.4f;
    avg_speed[0] = 83.5f;
    avg_speed[1] = 94.2f;
    avg_speed[2] = 48.2f;
    name = new char[strlen(given_name)+1];
    memcpy(name, given_name, strlen(given_name)+1);
}

Opel::~Opel()
{
    delete [] name;
}

float Opel::GetFuelCapacity()
{
    return maxfuel;
}

float Opel::GetFuelConsumption()
{
    return consumption;
}

float Opel::GetAvgSpeed(Weather condition)
{
    return avg_speed[condition];
}

char* Opel::GetName()
{
    return name;
}