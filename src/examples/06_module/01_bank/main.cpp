#include<iostream>
#include "bank_account.h"
using std::cout;
int main()
{
	//initial balance will come from another class that retrieves balance from a DB
	BankAccount account(100);//create an instance called account of the class
	cout<<"Balance: "<<account.get_balance()<<"\n\n";
	
	BankAccount new_account; //using constructor overload
	cout<<"Balance: "<<new_account.get_balance()<<"\n";
	display_bank_account_data(new_account);
	cout<<"Balance: "<<new_account.get_balance()<<"\n";//still displays 0

	BankAccount account = get_account();
	cout<<"Account balance: "<<account.get_balance()<<"\n";
	return 0;
}