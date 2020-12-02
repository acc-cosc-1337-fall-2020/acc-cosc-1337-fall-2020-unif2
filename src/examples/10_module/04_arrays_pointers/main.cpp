#include<iostream>

using std::cout;

int main() 
{
	const int SIZE = 3;
	int numbers[SIZE] {4,1,10};
	int* ptr = numbers;//create a pointer to numbers -- right now it's pointing to the first element

	//the name of an array is a pointer - we can point to it
	cout<<"Initial array address: "<<numbers<<"\n";//address of first element of the array
	cout<<"Initial size address: "<<&SIZE<<"\n";//address of SIZE

	cout<<"Value at ptr: "<<*ptr<<"\n";//4
	ptr++;//Advance to the next address
	cout<<"Value at ptr: "<<*ptr<<"\n";//1
	ptr++;//Advance to the next address
	cout<<"Value at ptr: "<<*ptr<<"\n";//10

	ptr--;//go back to previous address
	cout<<"Value at ptr: "<<*ptr<<"\n";//1
	ptr--;//go back to previous address
	cout<<"Value at ptr: "<<*ptr<<"\n";//4



	return 0;
}