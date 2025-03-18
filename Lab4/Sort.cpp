#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstring>
#include <stdarg.h>
Sort::Sort(int lenght, int min, int max)
{
    srand(time(0));
    len = lenght;
    list = new int[lenght];
    for (int ind = 0; ind < lenght; ind++)
    {
        list[ind] = rand()%(max - min + 1) + min;
    }
}
Sort::Sort(int lenght, int* sec_vec): len(lenght), list(new int[lenght]) {
    memcpy(list, sec_vec, 4*len);
}
Sort::Sort(int* vec, int lenght)
{
    list = new int(lenght);
    memcpy(list, vec, 4*lenght);
    len = lenght;
}
Sort::Sort(int nr, ...)
{
    va_list vl;
    va_start(vl, nr);
    list = new int[nr];
    len = nr;
    for (int ind = 0; ind < nr; ind++)
    {
        list[ind] = va_arg(vl, int);
    }
    va_end(vl);
}
Sort::Sort(char* vec)
{
    int nr = 0, ind = 0, poz = 0;
    len = 1;
    while (vec[ind])
    {
        if (vec[ind] == ',')
        {
            len++;
        }
        ind++;
    }
    list = new int[len];
    ind = 0;
    while (vec[ind])
    {
        if (vec[ind] == ',')
        {
            list[poz++] = nr;
            nr = 0;
        }
        else
        {
            nr = nr * 10 + vec[ind] - '0';
        }
        ind++;
    }
    list[poz] = nr;
}
void Sort::Print()
{
    for (int ind = 0; ind < len; ind++)
    {
        printf("%d ", list[ind]);
    }
}
void Sort::InsertSort(bool ascendent)
{
    int poz, aux;
    for (int ind = 1; ind < len; ind++)
    {
        poz = ind-1;
        while (poz >= 0 && ((ascendent && list[poz] > list[poz+1]) || (!ascendent && list[poz] < list[poz+1])))
        {
            aux = list[poz];
            list[poz] = list[poz+1];
            list[poz+1] = aux;
            poz--;
        }
    }
}
void Sort::BubbleSort(bool ascendent)
{
    int lenght = len, aux;
    bool exit = false;
    while (!exit && lenght > 1)
    {
        exit = true;
        for (int ind = 0; ind < lenght ; ind++)
        {
            if ((ascendent && list[ind] > list[ind+1]) || (!ascendent && list[ind] < list[ind+1]))
            {
                aux = list[ind];
                list[ind] = list[ind+1];
                list[ind+1] = aux;
                exit = false;
            }
        }
        lenght--;
    }
}
int Partition(int* list, int st, int dr, bool ascendent)
{
    int pivot = list[dr], ind2 = st-1, aux;
    for (int ind1 = st; ind1 < dr; ind1++)
    {
        if ((list[ind1] < pivot && ascendent) || (!ascendent && list[ind1] > pivot))
        {
            ind2++;
            aux = list[ind1];
            list[ind1] = list[ind2];
            list[ind2] = aux;
        }
    }
    ind2++;
    aux = list[ind2];
    list[ind2] = list[dr];
    list[dr] = aux;
    return ind2;
}
void Sort::QuickSort(int st, int dr, bool ascendent)
{
    if (st < dr)
    {
        int piv = Partition(this->list, st, dr, ascendent);
        QuickSort(st, piv-1, ascendent);
        QuickSort(piv+1, dr, ascendent);
    }
}
int Sort::GetElementsCount()
{
    return len;
}
int Sort::GetElementFromIndex(int index)
{
    return list[index];
}