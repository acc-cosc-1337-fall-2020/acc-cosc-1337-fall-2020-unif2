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
	cout<<string(1,'c')<<"\n";
	for(char c: name.substr(0,name.size()-1))
	{
		cout<<c<<"\n";
	}
	string last = string(1, name[name.size()-1]);
	cout<<last;
	return 0;
}