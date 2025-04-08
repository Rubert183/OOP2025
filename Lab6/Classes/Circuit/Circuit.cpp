#include "Circuit.h"
#include "../Car.h"
#include "../Weather.h"
#include <stdio.h>

Circuit::Circuit()
{
    nr_of_cars = 0;
}

void Circuit::AddCar(Car* new_car)
{
    if (nr_of_cars < 12)
    {
        cars[nr_of_cars] = new_car;
        nr_of_cars++;
    }
}

void Circuit::SetWeather(Weather weather)
{
    current_weather = weather;
}

void Circuit::SetLenght(int given_lenght)
{
    lenght = given_lenght;
}

void Circuit::Race()
{
    float aux_time;
    Car *aux_car;
    for (int ind = 0; ind < nr_of_cars; ind++)
    {
        time[ind] = lenght / cars[ind]->GetAvgSpeed(current_weather);
        if (cars[ind]->GetFuelCapacity() / cars[ind]->GetFuelConsumption() * 100 < lenght)
        {
            time[ind] = -1;
        }
    }
    for (int ind1 = 0; ind1 < nr_of_cars - 1; ind1++)
    {
        for (int ind2 = ind1 + 1; ind2 < nr_of_cars; ind2++)
        {
            if (time[ind1] > time[ind2])
            {
                aux_time = time[ind1];
                time[ind1] = time[ind2];
                time[ind2] = aux_time;

                aux_car = cars[ind1];
                cars[ind1] = cars[ind2];
                cars[ind2] = aux_car;
            }
        }
    }
}

void Circuit::ShowFinalRanks()
{
    int poz=0;
    for (int ind = 0; ind < nr_of_cars; ind++)
    {
        if (time[ind] > -1)
        {
            poz++;
            printf("#%d %s\n", poz, cars[ind]->GetName());
        }
    }
    for (int ind = 0; ind < nr_of_cars; ind++)
    {
        if (time[ind] == -1)
        {
            printf("DNF %s\n", cars[ind]->GetName());
        }
        else
        {
            break;
        }
    }
}

void Circuit::ShowWhoDidNotFinish()
{
    bool found = false;
    for (int ind = 0; ind < nr_of_cars; ind++)
    {
        if (time[ind] == -1)
        {
            found = true;
            printf("DNF %s\n", cars[ind]->GetName());
        }
        else
        {
            break;
        }
    }
    if (!found)
    {
        printf("All the participants finished\n");
    }
}

