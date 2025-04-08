#include "Classes/Mazda/Mazda.h"
#include "Classes/Mazda/Mazda.cpp"
#include "Classes/Bmw/Bmw.h"
#include "Classes/Bmw/Bmw.cpp"
#include "Classes/Circuit/Circuit.h"
#include "Classes/Circuit/Circuit.cpp"
#include "Classes/Opel/Opel.h"
#include "Classes/Opel/Opel.cpp"
#include "Classes/Volvo/Volvo.h"
#include "Classes/Volvo/Volvo.cpp"
#include "Classes/Car.h"
#include "Classes/Weather.h"
#include <stdio.h>

int main()
{
    Circuit c;

    c.SetLenght(30);
    c.SetWeather(SUNSET);

    c.AddCar(new Opel("Astra G Karavan"));
    c.AddCar(new Bmw("Red Bmw"));
    c.AddCar(new Mazda("Miata Na"));
    c.AddCar(new Volvo("Volvo3"));

    c.Race();
    c.ShowFinalRanks();
    c.ShowWhoDidNotFinish();

    return 0;
}