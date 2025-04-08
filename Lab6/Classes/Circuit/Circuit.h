#include "../Car.h"
#include "../Weather.h"
#pragma once

class Circuit
{
private:
    Car *cars[12];
    float time[12];
    int nr_of_cars, lenght;
    Weather current_weather;
public:
    Circuit();
    void AddCar(Car*);
    void SetWeather(Weather);
    void SetLenght(int);
    void ShowFinalRanks();
    void Race();
    void ShowWhoDidNotFinish();
};