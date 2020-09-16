#include "while.h"
#include<iostream>

using std::cout, std::cin;
int main() 
{
	int number;
	char choice = 'y';

	while(choice == 'y')
	{	
		cout<<"Enter a number: ";
		cin>>number;
		int sum = sum_of_squares(number);
		cout<<"Sum is: "<<sum<<"\n";
		cout<<"Enter y to continue: ";
		cin>>choice;
	}
	return 0;
}