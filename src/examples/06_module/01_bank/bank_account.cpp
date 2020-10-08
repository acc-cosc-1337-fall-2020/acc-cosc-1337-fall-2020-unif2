//bank_account.cpp
#include "bank_account.h"

void BankAccount::deposit(int amount) //tells compiler that deposit function belongs to that class
{
    if(amount > 0)
    {
        balance += amount;
    }
}