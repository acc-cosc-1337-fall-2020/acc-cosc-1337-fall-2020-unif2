#include<iostream>
#include "value_ref.h"
using std::cout; using std::cin;

int main() 
{	
	sample_static_var(); // value is 1
	sample_static_var(); // value is 2
	sample_static_var(); // value is 3

	pass_by_val_and_ref(5);
	int num1 = 5, num2 = 10;
	pass_by_val_and_ref(num1, num2);
	int num = 5;
	
	cout<<"Value of num: "<<num<<"\n";
	cout<<"Stack Address of num: "<<&num<<"\n";
	
	int& num_ref = num; //we can only reference a variable one time
	
	cout<<"Value of num_ref: "<<num_ref<<"\n";
	cout<<"Stack Address of num_ref: "<<&num_ref<<"\n";

	num_ref = 10; //we can modify the value of num via a reference variable
	cout<<"Value of num: "<<num<<"\n";
	cout<<"Value of num_ref: "<<num_ref<<"\n";
	
	return 0;
}