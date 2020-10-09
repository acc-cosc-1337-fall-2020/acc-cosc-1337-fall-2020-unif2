//bank_account.cpp
#include "bank_account.h"
#include<iostream>

BankAccount::BankAccount(int b) : balance(b)
{

}
void BankAccount::deposit(int amount) //tells compiler that deposit function belongs to that class
{
    if(amount > 0)
    {
        balance += amount;
    }
}
//void deposit(int amount) is called a free function in C++ (i.e. doesn't belong to a class)

void BankAccount::withdraw(int amount)
{
    if(amount > 0 && balance >= amount)
    {
        balance -= amount;
    }
}
void display_bank_account_data(BankAccount& b)
{   
    b.deposit(50);
    //b.deposit(50) modifies a copy just like value parameter
    std::cout<<"Balance: "<<b.get_balance()<<"\n";
    //adding & in parameter, i.e. passing BankAccount b as a reference, will allow us to change the balance with b.deposit(50)
}

BankAccount get_account()//return by value
{
    //Class that retrives DB balance and creates BankAccount
    BankAccount a(1000);
    return a;//returns a copy
}