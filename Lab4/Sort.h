#pragma once
class Sort
{
    int len, *list;
public:
    Sort(int, int, int);
    Sort(int, int*);
    Sort(int*, int);
    Sort(int, ...);
    Sort(char*);
    void InsertSort(bool ascendent=false);
    void QuickSort(int st, int dr, bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
