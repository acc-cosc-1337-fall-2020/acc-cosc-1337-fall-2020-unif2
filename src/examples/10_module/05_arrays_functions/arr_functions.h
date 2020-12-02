//header iterate_array function with int pointer array and size int for array size
#include<iostream>
#include<iomanip>

//Note: We're passing int nums[] by reference because nums is a pointer and pointers point to addresses
void iterate_array(int nums[], int size);//have to pass in size because the array doesn't know how big it is

const int ROWS = 10;
const int COLS = 10;

void arrays_and_pointers();

void populate_times_table(int times_table [][COLS], int ROW);

void display_times_table(int times_table [][COLS], int ROW);

void display_array(int* nums, int SIZE);

void dynamic_mem_int();