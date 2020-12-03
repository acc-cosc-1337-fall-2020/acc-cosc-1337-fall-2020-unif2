//
#include "vector.h"

int main()
{
    std::cout<<"Before function\n";
    use_stack_vector();//create memory and function exits, but if we don't call delete, memory would still be occupied/in use by our program (memory leak)
    //but if we have a destructor and call delete in the destructor, then memory will get deleted
    //running the above line will display "Create and init memory/elements" (from the constructor) 
    //then "Release memory from heap" (from the destructor) - no need to call delete in the function: the destructor does that for us
    std::cout<<"After function\n";

    std::cout<<"Before function\n";
    use_heap_vector();//creates memory but does not release it, unless we call delete in the function ourselves
    std::cout<<"After function\n";

    //Requires copy constructor to work properly.  Otherwise two Vector instances will point to the same memory
    //With the copy constructor, each will point to their own memory.
    Vector v1(3);
    Vector v2 = v1;//create new vector from the existing vector

    //
    Vector v3(3);
    Vector v4(3);
    v4 = v3;

    return 0;
}

