#include "do_while.h"
#include<iostream>
using std::cout, std::cin;
//Write code for void function prompt_user to loop until
//user opts not to continue.  
void prompt_user()
{
    char choice;
	do
	{   display_menu();
        cout<<"Select a number\n\n";
        int menu_choice;
        cin>>menu_choice;
        execute_menu_choice(menu_choice);
        if(menu_choice != 4)
        {
        cout<<"\nEnter y to continue: ";
		cin>>choice;
        }
        else
        {
            break;
        }
        
	} while (choice =='y' || choice == 'Y');
}
void display_menu()
{
    cout<<"1-Accounts Receivable\n";
    cout<<"2-Accounts Payable\n";
    cout<<"3-Payroll\n";
    cout<<"4-Exit \n";
}

void execute_menu_choice(int num)
{
    switch(num)
    {
        case 1:
        cout<<"You selected AR menu";
        break;
        
        case 2:
        cout<<"You selected AP menu";
        break;

        case 3:
        cout<<"You selected Payroll menu";
        break;

        case 4:
        cout<<"You will exit the program\n";
        break;

        default:
        cout<<"Invalid Option";
    }
}
