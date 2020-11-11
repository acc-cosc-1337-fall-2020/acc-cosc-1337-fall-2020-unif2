//write include statemetns

/*
Create a vector of rectangles
Add 3 Rectangle classes to the vector:
Width	Height		Area
  4		 5			  20
 10		10			 100
100		10			1000
Iterate the vector and display the Area for each Rectangle on one line and the total area for the
3 rectangles.
*/
#include<iostream>
#include<fstream>
#include<string>
int main()
{
  std::ofstream out_file;
  std::cout<<"Open file: \n";
  out_file.open("names.dat");

  out_file<<"joe"<<std::endl;
  out_file<<"may"<<std::endl;
  out_file<<"john"<<std::endl;

  std::cout<<"Close file\n";
  
  //READ FILE

  std::ifstream in_file;
  std::cout<<"\n open file\n\n";
  in_file.open("names.dat");

  std::string name;
  std::cout<<"Names\n";
  while(in_file>>name)
  {
    std::cout<<name<<"\n";
  }

  in_file.close();
	
	return 0;
}