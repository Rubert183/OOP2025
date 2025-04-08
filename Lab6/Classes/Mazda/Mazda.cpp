#include "Mazda.h"
#include <stdio.h>
#include <string.h>
#include "../Weather.h"

Mazda::Mazda(char* given_name)
{
    maxfuel = 100.f;
    consumption = 7.3f;
    avg_speed[0] = 80.5f;
    avg_speed[1] = 100.2f;
    avg_speed[2] = 40.2f;
    name = new char[strlen(given_name)+1];
    memcpy(name, given_name, strlen(given_name)+1);
}

Mazda::~Mazda()
{
    delete [] name;
}

float Mazda::GetFuelCapacity()
{
    return maxfuel;
}

float Mazda::GetFuelConsumption()
{
    return consumption;
}

float Mazda::GetAvgSpeed(Weather condition)
{
    return avg_speed[condition];
}

char* Mazda::GetName()
{
    return name;
}