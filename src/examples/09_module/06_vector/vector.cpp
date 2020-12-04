#include "vector.h"

template<class T>
Vector<T>::Vector() : size{0}, space{size}, elements{nullptr}
{
    std::cout<<"\nset size and space to 0 elements points to nullptr\n";
}

//
template<class T>
Vector<T>::Vector(size_t sz) : size{sz}, space{sz}, elements{new T[sz]}//initialize pointer elements (dyanmic array) to a dyanmic array of size sz
{
    std::cout<<"\nCreate and init memory at "<<elements<<"\n";//<<elements prints the address of first element of elements
    for(size_t i=0; i<sz; ++i)
    {
        elements[i] = 0;
    }
}

/*
Copy Constructor

1 - initialize size for v2
2 - initialize memory for v2
3 - copy element values from v1 into v2
*/
template<class T>
Vector<T>::Vector(const Vector<T>& v) : size{v.size}, elements{new T[v.size]}
{
    std::cout<<"Copy constructor Create and init memory at "<<elements<<"\n";
    for(size_t i=0; i<v.size; ++i)
    {
        elements[i] = v.elements[i];//v1 is the v and v2 is the left hand size
    }

}

/*
(v2 = v1)
1-Create temporary memory
2-Copy values from v1 into temporary memory
3-Delete class(v2) elements memory
4-Point elements memory to temporary memory
5-Return a reference to this vector
*/
template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
    T* temp = new T[v.size];
    std::cout<<"\ncopy assignment from "<<v.elements<<" to "<<elements<<"\n";

    for(size_t i=0; i<v.size; ++i)
    {
        temp[i] = v.elements[i];
    }

    delete[] elements;

    elements = temp;
    size = v.size;

    return *this;
}

/*
Move constructor
1 - get dynamic memory from v
2 - get size from v
3 - point v.elements to nullptr
4 - set v.size to 0
*/
template<class T>
Vector<T>::Vector(Vector<T> && v) : size{v.size}
{
    std::cout<<"\nmove constructor from "<<elements<<" to "<<v.elements<<"\n";
    elements = v.elements;
    v.elements = nullptr;
    v.size = 0;
}

/*
Move Assignment 
1 - Deallocate original dynamic memory
2 - Get dynamic memory from v
3 - Get the size from v
4 - Point v.elements to nullptr
5 - Set v.size to 0
*/
template<class T>
Vector<T> & Vector<T>::operator=(Vector<T> && v)
{
    std::cout<<"\nmove assignment from "<<elements<<" to "<<v.elements<<"\n";
    delete[] elements;
    elements = v.elements;
    size = v.size;
    v.elements = nullptr;
    v.size = 0;

    return *this;
}

/*
Reserve
1 - Make sure new_allocation is greater than space
2 - Create temporary dynamic array of size new_allocation
3 - Copy values from old memory array to temporary array
4 - Delete the old memory array (nums)
5 - Set elements to temporary memory array
6 - Set space = new_allocation
*/
template<class T>
void Vector<T>::Reserve(size_t new_allocation)
{
    if(new_allocation <= space)
    {
        return;
    }

    T* temp = new T[new_allocation];

    for(size_t i=0; i < size; ++i)
    {
        temp[i] = elements[i];
    }

    delete[] elements;
    elements = temp;

    space = new_allocation;
}

/*
1 - reserve new space of new_allocation size
2 - initialize elements greater than size
3 - set space to new_allocation
*/
template<class T>
void Vector<T>::Resize(size_t new_allocation)
{
    Reserve(new_allocation);

    for(size_t i=size; i<space; ++i)
    {
        elements[i] = 0;
    }

    space = new_allocation;
}

/*
Pushback
1 - if space equal to 0, add some space with RESERVE_DEFAULT_SIZE
2 - else if space == size, add twice (RESERVE_DEFAULT_MULTIPLIER) space new memory
3 - add value to element at size position
4 - increment size by 1
*/
template<class T>
void Vector<T>::Pushback(T value)
{
    if(space == 0)
    {
        Reserve(RESERVE_DEFAULT_SIZE);
    }
    else if(space == size)
    {
        Reserve(space * RESERVE_DEFAULT_MULTIPLIER);
    }

    elements[size] = value;
    size++;
}

//class destructor
template<class T>
Vector<T>::~Vector()
{
    std::cout<<"Release memory from heap from "<<elements<<"\n";
    delete[] elements;//using class structures to not leak memory
}

//Code that tells compiler what kind of datatypes we want to support. Only required because we're using
//both .h and .cpp for the template class
template class Vector<int>;
template class Vector<double>;
template class Vector<char>;

//FREE FUNCTION - NOT PART OF THE VECTOR CLASS
void use_stack_vector()//we don't have to call delete to release the memory - destructor does that
{
    Vector<int> v1(3);//recommended way - v1 doesn't take a lot of stack memory and all its data is on the heap
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
    Vector<int>* v1 = new Vector<int>(3);//creating dyanmic memory, which means we are taking charge of how to deal with the memory
    //use v1
    //100 lines of other code
    //Not releasing memory
    delete v1;
}

//FREE FUNCTION - NOT PART OF THE VECTOR CLASS
Vector<int> get_vector()
{
    Vector<int> v(3);
    return v;
    //after function finishes executing, v doesn't exist anymore
    //but before it doesn't exist, we can use the rvalue, which will give us access to memory and 
    //steal existing memory
}