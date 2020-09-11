#include<iostream>
#include "if.h"//to use is_even function here

using std::cout;
using std::cin;

int main() 
{
	//create a bool variable named even
	//create an int variable named value
	bool even;
	int value;

	//prompt user for a keyboard number
	cout<<"Enter a number: ";
	//assign the number to the value variable
	cin>>value;
	cout<<"Status of overtime: "<<overtime(value)<<"\n";
	//call the is_even function with value as its argument
	//and assign its return value to the even variable
	even = is_even(value);
	

	//display even if number is even
	if (even)
	{
		cout<<even<<"\n";
		cout<<"Value is even.\n";
	}
	else
	{
		cout<<even<<"\n";
		cout<<"Value is odd.\n";
	}
	

	return 0;
}
