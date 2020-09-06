//Write the include statement for types.h here
#include "types.h"
//Write include for capturing input from keyboard and displaying output to screen
#include<iostream>
using std::cout;
using std::cin;

int main() 
{
int num;
cin>>num; //User inputs a number
int result = multiply_numbers(num); //Apply the function to that number
cout<<result<<"\n"; //Display the result
int num1 = 4;
result = multiply_numbers(num1); //Apply the function to the number 4
cout<<result<<"\n"; //Display the result
return 0; //optional only in main function
}

