#include<iostream>
#include "atm.h"
#include "checking_account.h"
#include "savings_account.h"
#include "bank_account.h"
#include<stdlib.h>
#include<time.h>
#include<memory>
#include<vector>

using std::cout; using std::cin; using std::vector; using std::unique_ptr;
enum transaction{DEPOSIT = 1, WITHDRAW = 2, DISPLAY = 3};//legacy C++
enum class BANK_OPTIONS{DEPOSIT = 1, WITHDRAW = 2, DISPLAY = 3};

int main()
{
	/*
	BankAccount a;
	cout<<a.get_balance()<<"\n";
	CheckingAccount c(500);
	cout<<c.get_balance()<<"\n";

	a = c;
	cout<<a.get_balance()<<"\n";

	std::unique_ptr<BankAccount> up_a(new BankAccount());
	cout<<up_a->get_balance()<<"\n";
	std::unique_ptr<CheckingAccount> up_c = std::make_unique<CheckingAccount>(500);
	cout<<up_c->get_balance()<<"\n";

	//up_a = std::move(up_c);
	//cout<<up_a->get_balance()<<"\n\n";

	vector<unique_ptr<BankAccount>> accounts;//list
	accounts.push_back(std::move(up_a));
	accounts.push_back(std::move(up_c));

	cout<<"Display vector: \n";
	for(auto& account: accounts)
	{
		cout<<account->get_balance()<<"\n";
	}

	CheckingAccount ca(1000);
	cout<<ca.get_balance()<<"\n";

	SavingsAccount sa(500);
	cout<<sa.get_balance()<<"\n";
	srand(time(NULL));//generate a random number every time our program runs
	//BankAccount account(100), account1(500);
	//BankAccount account2 = account + account1;
	//out<<"Balance: "<<account2.get_balance()<<"\n\n";
	//cout<<account2;//this is calling the friend overload << function

	//cin>>account;
	//cout<<account;
	*/
	int choice;
	char cont;

	ATM atm;

	do
	{
		atm.scan_card();

		cout<<"Enter 1, 2, or 3";
		cin>>choice;

		switch (static_cast<BANK_OPTIONS>(choice))
		{
			case BANK_OPTIONS::DEPOSIT:
				cout<<"You selected deposit\n";
				break;
			case BANK_OPTIONS::WITHDRAW:
				cout<<"You selected withdraw\n";
				break;
			case BANK_OPTIONS::DISPLAY:
				atm.display_balance();
				break;
			default:
				cout<<"Invalid choice.\n";
		}
		cout<<"Enter y to continue: ";
		cin>>cont;
	} while (cont == 'y' || cont == 'Y');
	

	/*BranchBank bank(100000);
	bank.update_balance(500);
	cout<<"Branch balance: "<<bank.get_branch_balance()<<"\n";
	//initial balance will come from another class that retrieves balance from a DB

	BankAccount checking_account(100);//create an instance of the class called account
	cout<<"Branch balance: "<<bank.get_branch_balance()<<"\n";
	cout<<"Bank balance: "<<checking_account.get_bank_balance()<<"\n";
	display_balance(checking_account);

	int choice;

	/*cout<<"Balance: "<<checking_acount.get_balance()<<"\n\n";
	cout<<"Bank balance: "<<checking_account.get_bank_balance()<<"\n\n";

	BankAccount new_account;
	cout<<"Balance: "<<new_account.get_balance()<<"\n";

	display_bank_account_data(new_account);
	cout<<"Balance: "<<new_account.get_balance()<<"\n";
	cout<<"Bank balance: "<<new_account.get_bank_balance()<<"\n\n";


	BankAccount account = get_account();
	cout<<"Account balance: "<<account.get_balance()<<"\n\n";
	cout<<"Bank balance: "<<account.get_bank_balance()<<"\n\n";

	BankAccount copied_account = checking_account;
	cout<<"Balance checking: "<<checking_account.get_balance()<<"\n";

	cout<<"Balance copied: "<<copied_account.get_balance()<<"\n\n";

	//show class copy
	checking_account.deposit(100);
	copied_account.deposit(100);
	cout<<"Balance checking: "<<checking_account.get_balance()<<"\n";
	cout<<"Balance copied: "<<copied_account.get_balance()<<"\n\n";

	cout<<"Bank balance: "<<copied_account.get_bank_balance();*/
	
	return 0;
}