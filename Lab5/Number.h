#pragma once
class Number
{
   char *val;
   int base = 0;
   friend Number AddSameBase(const Number&, const Number&); //imp
   friend Number SubSameBase(const Number&, const Number&); //imp
public:
   Number(const char*, int); //imp
   Number(const Number& other); //imp
   Number(Number&& other); //imp
   Number(): val(nullptr) {}; //imp
   Number(const int);
   Number(const char*);
   ~Number(); //imp

   void operator=(const Number&); //imp
   char& operator[](const int); //imp

   friend bool operator<(const Number&, const Number&); //imp
   friend bool operator>(const Number&, const Number&); //imp
   friend bool operator<=(const Number&, const Number&); //imp
   friend bool operator>=(const Number&, const Number&); //imp
   friend bool operator==(const Number&, const Number&); //imp
   friend Number operator+(const Number&, const Number&); //imp
   friend Number operator-(const Number&, const Number&); //imp

   void operator+=(const Number&); //imp
   void operator-=(const Number&); //imp
   Number operator++(); //imp
   Number operator++(int); //imp
   void operator--(); //imp
   void operator--(int); //imp

   void SwitchBase(int newBase); //imp
   void Print(); //imp
   int  GetDigitsCount(); // returns the number of digits for the current number imp
   int  GetBase(); // returns the current base imp
};