#include<iostream>
#include "bank_account.h"
using std::cout;
int main()
{
	BankAccount account;//create an instance called account of the class
	cout<<"Balance: "<<account.get_balance();

	return 0;
}