#include<iostream>
#include "constants.h"
using std::cout;    using std::cin;
int main()
{
    double num;
    cout<<"Enter the radius: "<<"\n";
    cin>>num;
    cout<<"Area of circle is: "<<get_area_of_circle(num);
    return 0;
}