#include "arr_functions.h"
using std::cout;

int main() 
{
	const int SIZE = 3;
	int numbers[SIZE] {4,1,10};
	iterate_array(numbers, SIZE);//displays the elements of numbers 4 1 10 but changes last element to 1000
	for(int i=0;i<SIZE;++i)
	{
		cout<<numbers[i]<<"\n";//displays 4 1 1000
	}
	iterate_array_ptr(numbers, SIZE);//displays the elements 4 1 1000
	int times_table[ROWS][COLS];//initialize 2-D array with 10 Rows and 10 Columns
	arrays_and_pointers();
	populate_times_table(times_table, ROWS);

	display_times_table(times_table, ROWS);

	cout<<times_table<<"\n";

	int nums[ROWS]{};
	display_array(nums, ROWS);
	return 0;
}