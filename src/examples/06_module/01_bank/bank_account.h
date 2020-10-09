//bank_account.h
class BankAccount
{
public://access specifier
    //const makes a function read only. Putting it there makes it not possible for balance to be changed
    // in the function code.  all this function needs to do is return the balance, so it doesn't
    // need to be changed, therefore put const there to protect the balance data.
    //BankAccount(){}; //default constructor
    BankAccount() : BankAccount(0)/*Delegating constructor*/ {/*empty code block*/}//new accounts....constructor overload example
    //Code for the following constructor will be in the .cpp file at the top
    BankAccount(int b);// : balance(b){/*empty constructor code block*/}
    int get_balance()const{return balance;} //inline function //const so that nobody can modify balance in the function code
    void deposit(int amount);
    void withdraw(int amount);
    //in the book there is void set_deposit(int amount);//setter and getter methods
private://access specifier
    int balance{0};//private class member.  balance is not available to be used since it's private
    //use public if you want access to this variable. Users can modify it by using the deposit function.
};//VERY IMPORTANT DON'T FORGET THE SEMICOLON!!

//THESE FUNCTIONS DON'T BELONG TO THE BANKACCOUNT CLASS
void display_bank_account_data(BankAccount& b);//free function

BankAccount get_account();//free function that returns a BankAccount datatype