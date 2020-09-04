#include<iostream>
using std::cout;

int main() 
{
		auto num = 5;
		auto dec = .9;
		auto letter = 'a';
// auto num; doesn't work
// cannot use auto as function parameter
cout<<"Num is: "<<num<<" Dec: "<<dec<<" Letter: "<<letter;
	return 0;
}