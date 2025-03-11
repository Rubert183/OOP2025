#pragma once
class Student
{
    char* name;
    float math_grd, eng_grd, his_grd;
public:
    void set_name(const char* input_name);
    char* get_name();
    void set_math_grd(const float nr);
    float get_math_grd();
    void set_eng_grd(const float nr);
    float get_eng_grd();
    void set_his_grd(const float nr);
    float get_his_grd();
    float avg();
};
