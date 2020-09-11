//write include statements
#include "if_else.h"
#include<iostream>

//write cin and cout using statements
using std::cout;
using std::cin;

/*
Write code to capture year from keyboard.
Pass the year to get_generation function and display function result.
*/
int main() 
{
	int year;
	cout<<"Enter a year: \n";
	cin>>year;
	cout<<"Your generation is: "<<get_generation(year)<<"\n";
	return 0;
}