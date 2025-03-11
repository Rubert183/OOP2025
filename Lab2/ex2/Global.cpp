#include "Student.h"
#include <cstring>
int cmp_name(Student &s1, Student &s2)
{
    int ind = 0;
    char *name1 = s1.get_name(), *name2 = s2.get_name();
    while (name1[ind] && name2[ind])
    {
        if (name1[ind] > name2[ind])
        {
            return 1;
        }
        if (name1[ind] < name2[ind])
        {
            return -1;
        }
        ind++;
    }
    if (name1[ind] == '\0' && name2[ind] == '\0')
    {
        return 0; // au acelasi nume
    }
    if (name1[ind] == '\0')
    {
        return 1;
    }
    return -1;
}

int cmp_math(Student &s1, Student &s2)
{
    float math1 = s1.get_math_grd(), math2 = s2.get_math_grd();
    if (math1 == math2)
    {
        return 0;
    }
    if (math1 > math2)
    {
        return 1;
    }
    return -1;
}

int cmp_eng(Student &s1, Student &s2)
{
    float eng1 = s1.get_eng_grd(), eng2 = s2.get_eng_grd();
    if (eng1 == eng2)
    {
        return 0;
    }
    if (eng1 > eng2)
    {
        return 1;
    }
    return -1;
}

int cmp_his(Student &s1, Student &s2)
{
    float his1 = s1.get_his_grd(), his2 = s2.get_his_grd();
    if (his1 == his2)
    {
        return 0;
    }
    if (his1 > his2)
    {
        return 1;
    }
    return -1;
}

int cmp_avg(Student &s1, Student &s2)
{
    float avg1 = s1.avg(), avg2 = s2.avg();
    if (avg1 == avg2)
    {
        return 0;
    }
    if (avg1 > avg2)
    {
        return 1;
    }
    return -1;
}