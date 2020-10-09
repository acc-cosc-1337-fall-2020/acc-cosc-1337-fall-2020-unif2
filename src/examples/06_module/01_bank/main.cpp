#include<iostream>
#include "bank_account.h"
using std::cout;
int main()
{
	//initial balance will come from another class that retrieves balance from a DB
	BankAccount account(100);//create an instance of the class called account
	cout<<"Balance: "<<account.get_balance()<<"\n\n";//100
	
	BankAccount new_account; //using constructor overload
	cout<<"Balance: "<<new_account.get_balance()<<"\n";//0
	display_bank_account_data(new_account);//50
	cout<<"Balance: "<<new_account.get_balance()<<"\n";//50

	BankAccount account2 = get_account();
	cout<<"Account balance: "<<account2.get_balance()<<"\n";//1000
	return 0;
}