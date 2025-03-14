#include "Canvas.h"
#include "Canvas.cpp"
#include <iostream>

int main()
{
    Canvas obj(20, 15);
    obj.DrawCircle(5, 5, 4, '@');
    obj.FillCircle(5, 5, 4, '$');
    obj.Print();
    printf("\n");
    obj.Clear();
    obj.DrawRect(1, 1, 14, 10, '@');
    obj.FillRect(1, 1, 14, 10, '$');
    obj.Print();
    printf("\n");
    obj.Clear();
    obj.DrawLine(1, 1, 10, 10, '@');
    obj.Print();
    printf("\n");
    obj.Clear();
    obj.DrawLine(1, 1, 10, 7, '@');
    obj.Print();
    return 0;
}