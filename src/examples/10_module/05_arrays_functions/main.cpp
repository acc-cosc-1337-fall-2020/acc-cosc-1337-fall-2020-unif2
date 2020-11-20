#include "arr_functions.h"
using std::cout;

int main() 
{
	int times_table[ROWS][COLS];
	arrays_and_pointers();
	populate_times_table(times_table, ROWS);

	display_times_table(times_table, ROWS);

	cout<<times_table<<"\n";

	int nums[ROWS]{};
	display_array(nums, ROWS);
	return 0;
}