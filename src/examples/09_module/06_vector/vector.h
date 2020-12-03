//
#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include<iostream>
#include<cstddef>
#include<stddef.h>//these two include statements are for size_t and for Mac to recognize size_t

class Vector
{
    public:
        Vector(size_t sz);//constructor...size_t is an unsigned integer - starts at 1
        Vector(const Vector& v);//copy constructor Rule 1 of 3 for Rule of 3 - Legacy C++//crates new memory and when we copy it creates more memory instead of pointing to other memory
        Vector& operator=(const Vector& v);//copy assignment 2 of 3 for Rule of 3 Legacy C++
        size_t Size()const{return size;}
        int& operator[](size_t i){return elements[i];}//return a reference to an integer
        int& operator[](size_t i)const {return elements[i];}
        ~Vector();//destructor Rule 2 of 3 for Rule of 3 - Legacy C++

    private:
        size_t size;
        int* elements;//points to dyanic memory on the heap - points to an array

};

//FREE FUNCTIONS - not part of the Vector class
void use_stack_vector();
void use_heap_vector();

#endif