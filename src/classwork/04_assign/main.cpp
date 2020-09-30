//write includes statements
#include<iostream>
#include "loops.h"
//write using statements for cin and cout
using std::cout; using std::cin;

/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() 
{
	char choice;
	do
	{
		auto number{1.0};
		int prod;
		cout<<"Enter an integer between 1 and 10: ";
		cin>>number;
		while (number < 1 || number > 10)
		{
			cout<<"\nThe integer must be between 1 and 10.  Try again.\n";
			cout<<"Enter an integer between 1 and 10: ";
			cin>>number;
		}
		int num = number;
		prod = factorial(num);
		cout<<"\n"<<num<<"! = "<<prod;
		cout<<"\nEnter y to continue: ";
		cin>>choice;
	} while (choice == 'y' || choice == 'Y');
	
	return 0;
}