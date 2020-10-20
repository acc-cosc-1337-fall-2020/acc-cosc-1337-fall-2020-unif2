//bank_account.cpp
#include "bank_account.h"
#include<iostream>

BankAccount::BankAccount(int b) : balance(b)
{
    //code for validating data
    bank_balance += balance;
}
void BankAccount::deposit(int amount) //tells compiler that deposit function belongs to that class
{   //this->balance = balance; //set this balance overide the class balance
    //this self references the class in memory
    if(amount > 0)
    {
        balance += amount;
        bank_balance += amount;
    }
}
//void deposit(int amount) is called a free function in C++ (i.e. doesn't belong to a class)

void BankAccount::withdraw(int amount)
{
    if(amount > 0 && balance >= amount)
    {
        balance -= amount;
        bank_balance -= amount;
    }
}

int BankAccount::bank_balance = 0;

//FREE FUNCTION-FRIEND OF BANK ACCOUNT CLASS
void display_balance(const BankAccount& a)
{
    std::cout<<"Friend display balance: "<<a.balance<<"\n";
}

//FREE FUNCTIONS-DO NOT BELONG OT THE BANKACCOUNT CLASS
void display_bank_account_data(BankAccount& b)
{   
    b.deposit(50);//modifies the original b, so if you run this function in main, b's balance
    //in main will change to reflect a deposit of 50.  If BankAccount parameter is passed by value,
    //then running the function will not change the b in main().
    std::cout<<"Balance: "<<b.get_balance()<<"\n";
    //adding & in parameter, i.e. passing BankAccount b as a reference, will allow us to change the balance with b.deposit(50)
}

BankAccount get_account()//return by value....this is a function that creates a BankAccount object
{
    //Class that retrieves DB balance and creates BankAccount
    BankAccount a(1000);
    return a;//returns a copy
}

void BranchBank::update_balance(int b)
{
    branch_balance += b;
    BankAccount::bank_balance += b;
}