#include "variables.h"
//write code for multiply_numbers function here
//function returns product of num1 and num2

double get_sales_tax_amount(double meal_amount)
{
	const double tax_rate = 0.0675;
	return meal_amount * tax_rate;
}

double get_tip_amount(double meal_amount, double tip_rate)
{
	return meal_amount * tip_rate;
}


