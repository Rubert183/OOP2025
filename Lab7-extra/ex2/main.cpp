#include <stdio.h>
#include "Vector.h"
bool descrescator(int nr1, int nr2)
{
    return nr1 > nr2;
}
int main()
{
    Vector<int> v;

    v.insert(0, 10);
    v.insert(1, 5);
    v.insert(2, 20);
    v.insert(3, 33);
    v.print();
    
    Vector<int> w = v;

    v.remove(0);
    v.sort(descrescator);
    printf("%d\n", w[0]);

    v.print();
}