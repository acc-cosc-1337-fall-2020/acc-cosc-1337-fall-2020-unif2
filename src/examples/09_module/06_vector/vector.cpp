#include "vector.h"

//
Vector::Vector(size_t sz) : size{sz}, elements{new int[sz]}//initialize pointer elements (dyanmic array) to a dyanmic array of size sz
{
    std::cout<<"\nCreate and init memory/elements\n";
    for(size_t i=0; i<sz; ++i)
    {
        elements[i] = 0;
    }
}

/*
Copy Constructor

1 - initialize size for v2
2 - initialize memory for v2
3 - coopy element values from v1 into v2
*/
Vector::Vector(const Vector& v) : size{v.size}, elements{new int[v.size]}
{
    std::cout<<"Copy constructor create and init memory\n";
    for(size_t i=0; i<size; ++i)
    {
        elements[i] = v.elements[i];//v1 is the v and v2 is the left hand size
    }

}

Vector::~Vector()
{
    std::cout<<"Release memory from heap\n";
    delete[] elements;//using class structures to not leak memory
}

//FREE FUNCTION - NOT PART OF THE VECTOR CLASS
void use_stack_vector()//we don't have to call delete to release the memory - destructor does that
{
    Vector v1(3);//recommended way - v1 doesn't take a lot of stack memory and all its data is on the heap
    //we don't have to remember to call delete when we create v1. We've already set up that construct in the destructor 
    v1[0] = 10;
    std::cout<<v1[0]<<"\n";
    //100 lines of other code
}

//FREE FUNCTION - NOT PART OF THE VECTOR CLASS
void use_heap_vector()//we have to explicitly call delete to release the memory
{
    //create a pointer to Vector - create dynamic memory for this Vector
    //Here, we're not creating an array of vectors.  So we have to call delete
    Vector* v1 = new Vector(3);//creating dyanmic memory, which means we are taking charge of how to deal with the memory
    //use v1
    //100 lines of other code
    //Not releasing memory
    delete v1;
}

/*
1-Create temporary memory
2-Copy values from v1 into temporary memory
3-Delete class(v2) elements memory
4-Point elements memory to temporary memory
5-Return a reference to this vector
*/
Vector& Vector::operator=(const Vector& v)
{
    int* temp = new int[v.size];

    for(size_t i=0; i<v.size; ++i)
    {
        temp[i] = v.elements[i];
    }

    delete[] elements;

    elements = temp;
    size = v.size;

    return *this;
}