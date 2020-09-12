//write include statements
#include<iostream>
#include<cmath>
#include "variables.h"

//write namespace using statement for cout
using std::cout, std::cin;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal_amount, tip_rate, tip_amount, tax_amount, total;

	cout<<"Enter meal amount: ";
	cin>>meal_amount;
	tax_amount = get_sales_tax_amount(meal_amount);
	tax_amount = floor(tax_amount / 0.01 + 0.5) * 0.01;
	cout<<"Enter tip rate: ";
	cin>>tip_rate;
	tip_amount = get_tip_amount(meal_amount, tip_rate);
	tip_amount = floor(tip_amount / 0.01 + 0.5) * 0.01;
	total = tip_amount + tax_amount + meal_amount;
	cout<<"\nMeal Amount:    "<<meal_amount<<"\n";
	cout<<"Sales Tax:      "<<tax_amount<<"\n";
	cout<<"Tip Amount:     "<<tip_amount<<"\n";
	cout<<"Total:          "<<total<<"\n";

	return 0;
}
