//Write the include statement for decisions.h here
#include<iostream>
#include "decision.h"

//Write namespace using statements for cout and cin
using std::cout, std::cin;

int main() 
{
	auto num{0.0};
	cout<<"Enter a numerical grade: ";
	cin>>num;
	if(num >= 0 && num <= 100)
	{
		int grade = num;
		cout<<"\nYour letter grade using if is: "<<get_letter_grade_using_if(grade);
		cout<<"\nYour letter grade using switch is: "<<get_letter_grade_using_switch(grade)<<"\n";
	}
	else
	{
		cout<<"\nNumerical grade out of range.\n";
	}
	return 0;
}

