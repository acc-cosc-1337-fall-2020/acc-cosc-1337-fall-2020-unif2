#include "ref_pointers.h"
#include<iostream>
#include<memory>
#include<vector>
#include<utility>

using std::cout; using std::unique_ptr; using std::make_unique;

int main() 
{
	//Reference
	int num = 20, num2 = 25;
	int& num_ref = num;

	cout<<"Value of num: "<<num<<"\n";//20
	cout<<"Address of num: "<<&num<<"\n";
	cout<<"Address of num via num_ref: "<<&num_ref<<"\n";//same address as line 16
	cout<<"Value of num via num_ref: "<<num_ref<<"\n\n";//20

	cout<<"Value of num2: "<<num2<<"\n";//25
	cout<<"Address of num2: "<<&num2<<"\n\n";//different address (4 less than previous)

	num_ref = num2;//assigning the value of num2 to num

	cout<<"Value of num: "<<num<<"\n";//25
	cout<<"Value of num2: "<<num2<<"\n";//25
	cout<<"Address of num via num_ref: "<<&num_ref<<"\n\n";//same address as line 16

	//pointer
	int num1 = 10, num3 = 15;
	int* num_ptr = &num1;//pointers work with addresses (to work with values, use *)

	cout<<"Value of num1: "<<num1<<"\n";//10
	cout<<"Address of num1: "<<&num1<<"\n";
	cout<<"Addres of num1 via num_ptr: "<<num_ptr<<"\n";//same as line 34
	cout<<"Value of num1 via num_ptr: "<<*num_ptr<<"\n\n";//10

	num_ptr = &num3;//save the address of num3 to num_ptr

	cout<<"Address of num3: "<<&num3<<"\n";
	cout<<"Address of num3 via num_ptr: "<<num_ptr<<"\n";//same as line 40 (num_ptr now points to address of num3)
	cout<<"Value of num3 via num_ptr: "<<*num_ptr<<"\n\n";//15

	//create dynamic memory (heap) with a pointer
	int* ptr_num1 = new int(5);
	cout<<"Value of ptr_num1: "<<*ptr_num1<<"\n\n";//5

	delete ptr_num1;//delete when you don't need it to free up memory

	//smart pointers - unique pointers
	unique_ptr<int> up_num = make_unique<int>(100);
	cout<<"Value of smart pointer: "<<*up_num<<"\n\n";//100
	use_smart_pointer(up_num);//Use Smart pointer function: 100

	unique_ptr<int> up_num1 = get_smart_pointer();
	cout<<"Value of smart pointer: "<<*up_num1<<"\n\n";//500
	use_smart_pointer(up_num1);//Use Smart pointer function: 500

	unique_ptr<int> up_num2(new int(15));
	cout<<"Value of smart pointer: "<<*up_num2<<"\n\n";//15

	//what about ownership of unique pointer
	std::vector<unique_ptr<int>> numbers;
	numbers.push_back(std::move(up_num));//transfer ownership of up_num to numbers
	cout<<"Vector unique ptr at 0: "<<*numbers[0]<<"\n";//100
	cout<<"Address of up_num: "<<up_num<<"\n";//0x0
	cout<<"Address of numbers[0]: "<<numbers[0]<<"\n";//0x7f89d25026c0



	return 0;
}