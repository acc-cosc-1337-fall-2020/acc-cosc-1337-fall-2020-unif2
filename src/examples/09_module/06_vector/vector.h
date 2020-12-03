//
#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include<iostream>
#include<cstddef>
#include<stddef.h>//these two include statements are for size_t and for Mac to recognize size_t

class Vector
{
    public:
        Vector();//default constructor
        Vector(size_t sz);//constructor...size_t is an unsigned integer - starts at 1
        Vector(const Vector& v);//copy constructor Rule 1 of 3 for Rule of 3 - inherited from Legacy C++//creates new memory of the same size and copy values into the new memory and make sure pointer points to that new memory (when we copy it creates more memory instead of pointing to old memory)
        Vector& operator=(const Vector& v);//copy assignment Rule 2 of 3 for Rule of 3 - Legacy C++
        Vector(Vector && v);//&& is a rvalue.//move constructor 4 of 5 of rule of 5 -- C++ 11
        Vector & operator=(Vector && v);//move assignment 5 of 5 Rule of 5 - C++ 11
        size_t Size()const{return size;}
        size_t Capacity()const{return space;}
        void Reserve(size_t new_allocation);
        void Resize(size_t new_allocation);
        void Pushback(int value);
        int& operator[](size_t i){return elements[i];}//return a reference to an integer
        int& operator[](size_t i)const {return elements[i];}
        ~Vector();//destructor Rule 3 of 3 for Rule of 3 - Legacy C++

    private:
        size_t size;
        size_t space;//size + free slots/spaces
        int* elements;//points to dyanic memory on the heap - points to an array
        const int RESERVE_DEFAULT_SIZE {8};
        const int RESERVE_DEFAULT_MULTIPLIER {2};

};

//FREE FUNCTIONS - not part of the Vector class
void use_stack_vector();
void use_heap_vector();
Vector get_vector();

#endif