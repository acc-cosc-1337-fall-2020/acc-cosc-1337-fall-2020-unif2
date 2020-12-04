//cpp
#include "arrays_char.h"

using std::cout; using std::cin;

void use_char_array()
{
    const int SIZE = 5;
    char name[SIZE] = {'J', 'o', 'h', 'n'};
    //"John" has 4 letters, so the compiler will add a null terminator at position 4 in the name array.
    //If instead you had "JohnD", instead of the null terminator, you would have a 'D' in position 4.

    cout<<name<<"\n";

    for(int i=0; name[i] != '\0'; ++i)
    {
        cout<<name[i]<<"\n";
    }

    //Or we can add null terminator ourselves
    char name1[SIZE] = {'J', 'o', 'h', 'n', '\0'};

    //Or we can initialize like this
    const int SIZE2 = 4;
    char name2[SIZE2];
    name2[0] = 'j';
    name2[1] = 'o';
    name2[2] = 'e';
    //compiler adds the null terminator for us, but before people had to explicitly add it:
    //name2[3] = '\0';
    //to be safe, explicitly add it yourself just in case you're working with an older compiler

    cout<<name2<<"\n";

    for(int i=0; name2[i] != '\0'; ++i)
    {
        cout<<name2[i]<<"\n";
    }

}

void use_dyn_char_array()
{
    const int SIZE = 10;
    //creating dynamic memory
    char* name = new char[SIZE];//pointer to char
    //once we use new, we are telling the compiler that we are responsible for the managing of the
    //dynamic memory and the compiler lets us handle it
    //if we used unique_ptr, it deletes the memory for us

    cout<<"Enter name: ";
    cin.getline(name, SIZE);
    cout<<name<<"\n";

    delete[] name;//should delete the memory once we are done using it, otherwise you will have a memory leak
    //i.e. once the function exits, we'll still have that memory there
    //we also have to remember to use delete in the destructor of a class that uses dynamic memory, otherwise
    //we'll have memory leak
    //if we put delete[] in the destructor, then anytime the class is used anywhere in our program, like inside a function,
    //then once the function exits, the destructor will run, thereby deleting the dyanmic memory that the class created
    //and the class will get deleted from the stack memory
    //However, if we make a new pointer to our class (example: if we have
    //Vector<int>* v1 = new Vector<int>(3);), then we have to remember to use delete[]
    //But if we want to use the above stuff with char and not worry about using delete[], then just use
    //the string class, since that does the deleting for us (programmers of the string class
    //programmed it that way).  The string class will create memory behind the scenes, put it on the heap, and we
    //just have to use it and once the string is out of scope (i.e. not being used in that function anymore) then that
    //dynamic memory is going to be deleted behind the scenes.

    //Recommendation: use string class, vector class, or unique_ptr.  That way, you won't have to worry
    //about memory management

}