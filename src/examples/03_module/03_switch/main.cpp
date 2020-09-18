#include<iostream>
#include "switch.h"

using std::cout, std::cin;

int main() 
{
	int option, y=0, z=0;
	cout<<"Enter a number: ";
	cin>>option;

	std::string result = menu(option);

	cout<<"\n"<<result;	
	// Immediate if
	option > 4 ? y = 10 : z = 20; //if option > 4 then y = 10, else z = 20
	cout<<"\n"<<y<<" "<<z;

	int option2;
	int choice;
	cout<<"Enter 0 for switch with number: ";
	cin>>option2;
	if(option2==0)
	{
	cout<<"Enter a number: ";
	cin>>choice;

	std::string result = menu(choice);

	cout<<"\n"<<result;	
	}
	else
	{
		char letter;
		cout<<"Enter a letter: ";
		cin>>letter;
		cout<<menu2(letter);
	}
	
	// Immediate if
	//option > 4 ? y = 10 : z = 20; //if option > 4 then y = 10, else z = 20
	//cout<<"\n"<<y<<" "<<z;
	return 0;
}