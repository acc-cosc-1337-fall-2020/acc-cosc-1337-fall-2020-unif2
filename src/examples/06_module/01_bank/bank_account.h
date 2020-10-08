//bank_account.h
class BankAccount
{
public://access specifier
    int get_balance()const{return balance;} //inline function //const so that nobody can modify balance in the function code
    void deposit(int amount);
private://access specifier
    int balance{0};//class member.  balance is not available to be used since it's private
    //use public if you want access to this variable
};//VERY IMPORTANT DON'T FORGET THE SEMICOLON!!