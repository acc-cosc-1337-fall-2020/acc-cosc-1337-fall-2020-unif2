//
#include "arr_functions.h"
using std::cout;
//define iterate_array and loop through with ++ increment

void arrays_and_pointers()
{
    const int SIZE = 3;
	int nums[SIZE]{3,6,1};
	//cout<<nums[0]<<"\n";
	//cout<<nums[1]<<"\n";
	//cout<<nums[2]<<"\n";

	cout<<nums<<"\n";//displays address of first element
    cout<<&nums[0]<<"\n";//displays address of first element
	int* ptr = nums;
	cout<<*ptr<<"\n";//3  i.e. ptr points to the first value of nums
	*ptr++;
	cout<<*ptr<<"\n";//outputs 6
	*ptr++;
	cout<<*ptr<<"\n";//outputs 1
}

void populate_times_table(int times_table [][COLS], int ROW)
{
    for(int i=0; i<ROW; ++i)
    {
        for(int j=0; j<COLS; ++j)
        {
            times_table[i][j] = (i+1) * (j+1);
        }
    }
}

void display_times_table(int times_table [][COLS], int ROW)
{
    for(int i=0; i<ROW; ++i)
    {
        for(int j=0; j<COLS; ++j)
        {
            cout<<std::setw(5)<<times_table[i][j];
        }
        cout<<"\n";
    }
}

void display_array(int* nums, int SIZE)
{
    for(int i=0; i<SIZE; ++i)
    {
        cout<<nums[i]<<"\n";
    }
}

void dynamic_mem_int()
{
    int* ptr = new int(5);
    //use it

    delete ptr;
    ptr = nullptr;

    //some more lines of code
}