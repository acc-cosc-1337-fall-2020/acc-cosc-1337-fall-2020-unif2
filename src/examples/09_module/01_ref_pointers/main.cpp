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
	int& num_ref = num;//C++ understands that you want to get the address of num

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
	//int* num_ptr = &num1;//declare a pointer and initialize it.  pointers work with addresses (to work with values, use *)
	int* num_ptr = nullptr;//delare a pointer but it's not pointing to anything yet.
	num_ptr = &num1;//now point it to something...i.e, initialize the pointer with address of num1
	int* num_ptr{};//same as int* num_ptr = nullptr;
	num_ptr = &num1;
	int* num_ptr1 = 0;
	if(*num_ptr == *num_ptr1)//always de-reference to work with values!
	{
		//code
	}

	/*
	if(num_ptr != nullptr)
	{

	}
	else
	{
		//error not initialized
	}*/
	

	cout<<"Value of num1: "<<num1<<"\n";//10
	cout<<"Address of num1: "<<&num1<<"\n";
	cout<<"Addres of num1 via num_ptr: "<<num_ptr<<"\n";//same as line 34
	cout<<"Value of num1 via num_ptr: "<<*num_ptr<<"\n";//10
	cout<<"Address of num_ptr: "<<&num_ptr<<"\n\n";

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

	int n1 = 1, n2 = 2;

	ref_ptr(n1, &n2);//n1 is a reference parameter, n2 is a pointer parameter
	cout<<n1<<"\n";//10
	cout<<n2<<"\n";//20

	//pointer to CONST

	const int SIZE = 5;
	//SIZE = 10; will give an error since SIZE is const
	const int* ptr_size = &SIZE;//pointer cannot modify SIZE, since SIZE is const
	//int* ptr_size = &SIZE; will give an error, so we have to make the pointer const
	cout<<*ptr_size<<"\n";//gives the value of SIZE

	ptr_size = &num1;//now let's make ptr_size point to the address of num1, which is not a const.  This is OK.
	cout<<*ptr_size<<"\n";//gives the value of num1
	//*ptr_size = 23;//gives an error because const int* ptr_size means whatever we point to we can only point to it in read only mode, so we cannot modify its value

	const int SIZE2 = 10;//but we can still make it point to another const variable or even a non-const variable.  We just won't be able to modify its value.
	ptr_size = &SIZE2;

	cout<<*ptr_size<<"\n";

	int n=5;
	ptr_size = &n;

	cout<<*ptr_size<<"\n";
	
	//*ptr_size = 10;//cannot modify the value

	cout<<*ptr_size;
	//So, a pointer to const points to a constant item.  The value the pointer points to cannot change.  But the pointer can change.  It can be reassigned to another address.


	//const pointer - works like a reference?
	//(once we assign the reference to an address, we cannot reassign it to a different address)

	int* const ptr1 = &n;//this is a constant (pointer is constant)-assign only once...can't be reassigned to another address
	cout<<"Value of n: "<<*ptr1<<"\n";//displays the value of n, which is 5
	//ptr1 = &n1;//attempting to assign it to another address, which we cannot do because it was declared const
	//i.e. ptr1 is read only, meaning we cannot change it.  So it works like a reference, in that we assign it an addresss and we cannot reassign it.
	*ptr1 = 25;
	cout<<"Value of n: "<<*ptr1<<"\n";//displays 25.  So we can change the value of n1, we just can't make ptr1 point to another address.

	//So, the pointer iteself is const.  Once it's assigned an address, it cannot be assigned to another address but we can change the value of the variable it points to.


	const int* const ptr2 = &SIZE;//const pointer to const. So it cannot change the value AND it cannot be reassigned a different address.
	
	int blah = 5, blah1 = 5;

	int* blah_ptr = &blah;
	int* blah1_ptr = &blah1;

	if(blah1_ptr == blah_ptr)
	{
		cout<<"equal";
	}
	else
	{
		cout<<"not equal";
	}
	//outputs not equal, but *blah1_ptr == *blah_ptr outputs equal
	
	return 0;
}