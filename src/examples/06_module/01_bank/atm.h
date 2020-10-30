//atm.h
#include<stdlib.h>//rand()
#include "bank_account.h"
#include<iostream>
#include<vector>
#include "customer.h"

#ifndef ATM_H
#define ATM_H

class ATM
{
public:
    //ATM(BankAccount& a) : account(a){}
    ATM();
    void scan_card();
    void display_balance();
private:
    std::vector<Customer> customers;
    int customer_index;
    int account_index;
    //BankAccount& account;
};

#endif