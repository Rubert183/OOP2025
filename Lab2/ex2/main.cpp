#include <iostream>
#include "Student.h"
#include "Student.cpp"
#include "Global.cpp"

void show_message(const char* message, int state)
{
    if (state == 1)
    {
        printf("The first student has a better %s\n", message);
    }
    else if (state == -1)
    {
        printf("The second student has a better %s\n", message);
    }
    else
    {
        printf("The students have the same %s\n", message);
    }
}

int main()
{
    Student s1, s2;
    s1.set_name("Bogdan");
    s1.set_eng_grd(9.f);
    s1.set_math_grd(9.f);
    s1.set_his_grd(9.f);

    s2.set_name("Alex");
    s2.set_eng_grd(5.1);
    s2.set_his_grd(6.123);
    s2.set_math_grd(8.9);

    show_message("name", cmp_name(s1, s2));
    show_message("english grade", cmp_eng(s1, s2));
    show_message("math grade", cmp_math(s1, s2));
    show_message("history grade", cmp_his(s1, s2));
    show_message("average grade", cmp_avg(s1, s2));

    return 0;
}