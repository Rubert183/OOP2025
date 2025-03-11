#include <stdlib.h>
#include "NumberList.h"
#include <iostream>
#include "NumberList.cpp"

int main()
{
    NumberList obj;
    obj.Init();
    for (int ind = 13; ind > 0; ind --)
    {
        obj.Add(ind);
    }
    obj.Print();
    obj.Sort();
    obj.Print();
}