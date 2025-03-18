#include "Sort.h"
#include "Sort.cpp"

int main()
{
    int vec[] = {6, 1, 2, 9, 10, 44};
    Sort obj1(6, 30, 40), obj2(6, vec), obj3(vec, 6), obj4(5, 4, 2, 1, 3, 5), obj5((char*)"24,67,12,11\0");

    printf("Initial list: ");
    obj1.Print();
    printf("\nSorted: ");
    obj1.BubbleSort();
    obj1.Print();
    printf("\n\n");

    printf("Initial list: ");
    obj2.Print();
    printf("\nSorted: ");
    obj2.InsertSort();
    obj2.Print();
    printf("\n\n");

    printf("Initial list: ");
    obj3.Print();
    printf("\nSorted: ");
    obj3.QuickSort(0, 5, true);
    obj3.Print();
    printf("\n\n");

    printf("Initial list: ");
    obj4.Print();
    printf("\nSorted: ");
    obj4.QuickSort(0, 4);
    obj4.Print();
    printf("\n\n");

    printf("Initial list: ");
    obj5.Print();
    printf("\nSorted: ");
    obj5.InsertSort(true);
    obj5.Print();
}