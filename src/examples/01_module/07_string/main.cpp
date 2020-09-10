#include<string>
#include<iostream>

using std::string;
using std::cout;

int main() 
{
	//Create string variable and display it		
	string name = "John Doe"; //string is a class
	int num; // int is a datatype
	cout<<"Size is: "<<name.size();//usually use size
	cout<<"Length is: "<<name.length();//probably same as size
	return 0;
}