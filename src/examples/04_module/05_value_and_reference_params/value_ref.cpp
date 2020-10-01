#include "value_ref.h"
#include<iostream>
int get_area(int height, int width)
{
    return height*width;
}
/*
Write function code for pass_by_val_and_ref with
a value int num1 and ref int num2 parameter.
The function assigns 20 to num1 and 50 to num2

@param int val
@param int& val

@return does not return a value
*/
void pass_by_val_and_ref(int num1, int& num2) //num1 is a value parameter, num2 is a reference parameter
{
    num1 = 20;
    num2 = 50;
    std::cout<<num1<<"\n";

}


/*
Function pass_by_const_ref 

Try to assign a value to num1, generates error.
@param const int& num

@return does not return a value
*/
void pass_by_const_ref(const int& num3) //for when you don't trust anyone (const is read only permissions and int& is so we don't make copies of the data to manage memory)
{
    // it will point to an existing variable, but it will not change it (it has read-only
    // access)
    //num = 50; we can't modify num due to the const keyword
    //can only display it or use it for some calculation

}

void sample_static_var()
{
    static int cnt = 0; //cnt exists as long as our program runs...NOT function.
    // stored in static memory, not the stack.
    cnt++;
    std::cout<<cnt<<"\n";

}