//bank_account.h
#include<iostream>
#ifndef BRANCH_BANK_H
#define BRANCH_BANK_H

class BranchBank
{
public:
    BranchBank(int b) : branch_balance(b){}
    void update_balance(int b);
    int get_branch_balance()const{return branch_balance;}

private:
    int branch_balance;
};

#endif

#ifndef BANK_ACCOUNT_H//header guards
#define BANK_ACCOUNT_H//header guards
class BankAccount
{
public://access specifier
    //const makes a function read only. Putting it there makes it not possible for balance to be changed
    // in the function code.  all this function needs to do is return the balance, so it doesn't
    // need to be changed, therefore put const there to protect the balance data.
    //BankAccount(){}; //default constructor
    BankAccount() = default;//behave like the default constructor C++ creates
    //BankAccount() : BankAccount(0)/*Delegating constructor*/ {/*empty code block*/}//new accounts....constructor overload example
    //Code for the following constructor will be in the .cpp file at the top
    explicit BankAccount(int b);// : balance(b){/*empty constructor code block*/}
    int get_balance()const{return balance;} //inline function //const so that nobody can modify balance in the function code
    int get_customer_no()const{return customer_no;}
    void deposit(int amount);
    void withdraw(int amount);
    friend void display_balance(const BankAccount& a);//NOT A CLASS FUNCTION-it is a free function
    friend void BranchBank::update_balance(int b);
    //in the book there is void set_deposit(int amount);//setter and getter methods
    static int get_bank_balance(){return bank_balance;}
    friend std::ostream& operator<<(std::ostream& out, const BankAccount& a);
    friend std::istream& operator>>(std::istream& in, BankAccount& a);
    friend BankAccount operator+(const BankAccount& a1, const BankAccount& a2);

protected:
    int balance {0};//class member

private://access specifier
    int customer_no;
    static int bank_balance;//private class member.  balance is not available to be used since it's private
    //use public if you want access to this variable. Users can modify it by using the deposit function.
};//VERY IMPORTANT DON'T FORGET THE SEMICOLON!!
#endif //header guards
//THESE FUNCTIONS DON'T BELONG TO THE BANKACCOUNT CLASS
void display_bank_account_data(BankAccount& b);//free function
BankAccount get_account();//free function that returns a BankAccount datatype