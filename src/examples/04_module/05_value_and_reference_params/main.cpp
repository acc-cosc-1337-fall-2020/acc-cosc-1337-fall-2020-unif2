#include<iostream>
#include "value_ref.h"
#include<memory>
#include<utility>

using std::cout; using std::cin;
using std::unique_ptr; using std::make_unique;

int main() 
{	/*
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
	cout<<"Value of num_ref: "<<num_ref<<"\n";*/

	int num = 5, num1 = 10;
    int& num_ref = num;
    cout<<"Value of num_ref: "<<num_ref<<"\n";
    cout<<"Address of num_ref: "<<&num_ref<<"\n";

    num_ref = num1;//copies the value not the address of num1

    cout<<"Value of num_ref: "<<num_ref<<"\n";
    cout<<"Address of num_ref: "<<&num_ref<<"\n";
    cout<<"Address of num"<<&num<<"\n";
    cout<<"Address of num1"<<&num1<<"\n";
    //num_ref = 15;

    cout<<"Value of num_ref: "<<num_ref<<"\n";
    cout<<"Value of num1: "<<num1<<"\n";
    num1 = 20;
    cout<<"Value of num_ref: "<<num_ref<<"\n";
    cout<<"Value of num1: "<<num1<<"\n";

    //pointer
    int num2 = 10, num3 = 20;
    int* ptr_num = &num2;//? why &

    cout<<"Value of num2 "<<num2<<"\n";
    cout<<"Address of num2"<<&num2<<"\n";
    cout<<"Address of ptr_num points to "<<ptr_num<<"\n";
    cout<<"Value ptr_num points to "<<*ptr_num<<"\n";

    *ptr_num = 100;

    cout<<"Value of num2 "<<num2<<"\n";
    cout<<"Address of num2"<<&num2<<"\n";
    cout<<"Address of ptr_num points to "<<ptr_num<<"\n";
    cout<<"Value ptr_num points to "<<*ptr_num<<"\n";

    cout<<"Address of num3 "<<&num3<<"\n";
    ptr_num = &num3;//reassign the pointer
    cout<<"Address of ptr_num points to "<<ptr_num<<"\n";
    cout<<"Value ptr_num points to "<<*ptr_num<<"\n";
    *ptr_num = 50;
    cout<<"Address of ptr_num points to "<<ptr_num<<"\n";
    cout<<"Value ptr_num points to "<<*ptr_num<<"\n";
    cout<<"Address of num3 "<<&num3<<"\n";

    //Create memory
    int* ptr_num = new int(5);//create a dynamic instance of an integer with value 5
    cout<<*ptr_num<<"\n";//use memory
    delete ptr_num; //delete memory

    //smart pointers
    unique_ptr<int> num5 = make_unique<int>(50);
    cout<<*num5;

    use_smart_pointer(num5);

    unique_ptr<int> num6 = get_smart_pointer();
    use_smart_pointer(num6);

    std::vector<unique_ptr<int>> nums;
    nums.push_back(std::move(num));
    cout<<*nums[0];
    for(auto& num: nums)
    {
        cout<<*num;
    }
	
	return 0;
}