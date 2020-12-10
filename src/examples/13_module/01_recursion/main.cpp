#include "recursion.h"

int main() 
{
	std::cout<<"load stack 5\n";
	//display(3);
	int f = factorial(5);
	std::cout<<"unload stack 5\n";
	std::cout<<"Factorial: "<<f<<"\n";
		
	return 0;
}