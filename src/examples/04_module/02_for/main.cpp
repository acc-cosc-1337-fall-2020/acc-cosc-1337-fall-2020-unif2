#include"for.h"
#include<iostream>
int main() 
{
	int value;
	char choice = 'y';
	while(choice=='y'||choice=='Y'){
	std::cout<<"Enter a number: ";
	std::cin>>value;
	display_numbers(value);
	int result;
	result = sum_numbers(value);
	std::cout<<"\nResult: "<<result;
	std::cout<<"\nEnter y to continue: ";
	std::cin>>choice;
	}
	return 0;
}