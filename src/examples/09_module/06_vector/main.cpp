//
#include "vector.h"
#include<utility>

int main()
{
    /*
    int num = add(5, 5);
    std::cout<<num<<"\n";

    double num1 = add(1.5, 4.9);
    std::cout<<num1<<"\n";
    */

    /*
    std::cout<<"Before function\n";
    use_stack_vector();//create memory and function exits, but if we don't call delete, memory would still be occupied/in use by our program (memory leak)
    //but if we have a destructor and call delete in the destructor, then memory will get deleted
    //running the above line will display "Create and init memory/elements" (from the constructor) 
    //then "Release memory from heap" (from the destructor) - no need to call delete in the function: the destructor does that for us
    std::cout<<"After function\n";

    std::cout<<"Before function\n";
    use_heap_vector();//creates memory but does not release it, unless we call delete in the function ourselves
    std::cout<<"After function\n";
    */

    //Requires copy constructor to work properly.  Otherwise two Vector instances will point to the same memory
    //With the copy constructor, each will point to their own memory.
    Vector<int> v1(3);
    Vector<int> v2 = v1;//create new vector from the existing vector
    v1[0] = 5;

    std::cout<<v1[0]<<"\n";
    
    Vector<double> v3(3);
    Vector<double> v4(3);
    v4 = v3;
    v4[1] = 10;

    std::cout<<v4[1]<<"\n";

   
   //requires move constructor
   //copy constructor executes here
   Vector<char> v(3);
   Vector<char> v_m = std::move(v);//uses the move constructor, which switches the pointers, and then after
   //return 0, we release memory from the heap
   v_m[0] = 'a';
   v_m[1] = 'b';
   std::cout<<v_m[0]<<"\n";
   std::cout<<v_m[1]<<"\n";

    /*
    //no move assignment
    Vector v(3);//new memory created (y50)
    v = get_vector();//get_vector() creates more memory (y34)
    //Copy Assignment executes, which creates new memory (y66) and moves memory, which we don't want to do
    //see diagram "No move assignment"*/

    /*
    //With move assignment (requires move assignment)
    Vector v(3);//memory is created (y50)
    v = get_vector();//memory is created by get_vector() (y34)
    //move assignment runs and instead of v pointing to y50, it points to y34
    //invalidate v's original memory at y50 (set it to 0) and point to y34 and when we release memory,
    //we release memory correctly.  So no unecessary copies.  More efficient.
    */

   /*
   Vector v;
   v.Pushback(4);

   std::cout<<v[0]<<"\n";

   v.Pushback(10);
   std::cout<<v[1]<<"\n";
   */

    return 0;//release memory from the heap
}

