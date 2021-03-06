#include "while.h"
#include<iostream>
//Using a while loop write code for sum_of_squares function that accepts an int and returns  
//the sum of all the squares of that number from 1 to the number. 
//Example: sum_of_squares(4) 
//1*1 + 2 * 2 + 3*3 + 4*4 = 30
int sum_of_squares(int num)
{
    int sum = 0;
    int cnt = 0;

    while(cnt <= num)
    {
        sum += cnt*cnt; // sum = sum + num*num;
        cnt++; //can also say num -= 1; or num = num - 1;
    }
    std::cout<<"sum of squares num before "<<num<<"\n";
    num = 10;
    std::cout<<"sum of squares num after "<<num<<"\n";
    return sum;
}

/*
int sum_of_squares(int num)
{
    int sum = 0, i=1;
    while(i <= num)
    {
        sum += i*i;
        i++;
    }
    return sum;
}

//Using a while loop write code for display function that accepts a string and displays 
//each character of the string in a line
//Example: display("Hello")
/*
result:

H
e
l
l
0

*/

