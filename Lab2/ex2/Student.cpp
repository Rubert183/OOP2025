#include <cstring>
#include "Student.h" 
void Student::set_name(const char* input_name)
{
    size_t length = strlen(input_name) + 1;
    name = new char[length];
    memcpy(name, input_name, length);
}

char* Student::get_name()
{
    return this->name;
}

void Student::set_math_grd(const float nr)
{
    if (nr >= 1.f && nr <= 10.f) 
    {
        this->math_grd = nr;
    }
}

float Student::get_math_grd()
{
    return this->math_grd;
}

void Student::set_eng_grd(const float nr)
{
    if (nr >= 1.f && nr <= 10.f) 
    {
        this->eng_grd = nr;
    }
}

float Student::get_eng_grd()
{
    return this->eng_grd;
}

void Student::set_his_grd(const float nr)
{
    if (nr >= 1.f && nr <= 10.f) 
    {
        this->his_grd = nr;
    }
}

float Student::get_his_grd()
{
    return this->his_grd;
}

float Student::avg()
{
    return (this->math_grd + this->eng_grd + this->his_grd) / 3.0f;
}