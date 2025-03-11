#include "NumberList.h"
#include <iostream>
void NumberList::Init()
{
    this->count = 0;
}

bool NumberList::Add(int x)
{
    if (this->count >= 10)
    {
        return false;
    }
    this->numbers[this->count++] = x;
    return true;
}

void NumberList::Sort()
{
    int aux;
    for (int ind1 = 0; ind1 < this->count - 1; ind1++)
    {
        for (int ind2 = ind1 + 1; ind2 < this->count; ind2++)
        {
            if (this->numbers[ind2] < this->numbers[ind1])
            {
                aux = numbers[ind2];
                numbers[ind2] = numbers[ind1];
                numbers[ind1] = aux;
            }
        }
    }
}

void NumberList::Print()
{
    for (int ind = 0; ind < this->count; ind++)
    {
        printf("%d ", this->numbers[ind]);
    }
    printf("\n");
}