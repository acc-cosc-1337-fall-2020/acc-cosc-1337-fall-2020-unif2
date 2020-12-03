#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
//#include "types.h"
#include "ref_pointers.h"
#include "vector.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test reference and pointer function parameters")
{
	int n1 = 1, n2 = 2;
	ref_ptr(n1, &n2);

	REQUIRE(n1 == 10);
	REQUIRE(n2 == 20);
}

TEST_CASE("Reference and pointer function parameters use a pointer")
{
	int n1 = 1, n2 = 2;

	int* ptr = &n2;//make a pointer that points to n2

	ref_ptr(n1, ptr);
	REQUIRE(n1==10);
	REQUIRE(n2==20);
}

TEST_CASE("Test create Vector from existing Vector instance - compare size")
{
	Vector v1(3);
	Vector v2 = v1;

	REQUIRE(v1.Size() == v2.Size());//passes, but the following gets printed:
	// Create and init memory/elements
	// Copy constructor create and init memory
	// Release memory from heap
	// Release memory from heap
	// (so memory is released twice...something is wrong here)
}

TEST_CASE("Test create vector from existing vector instance - compare elements")
{
	Vector v1(3);
	Vector v2 = v1;//v2's elements points to same elements array as v1

	v1[0] = 5;
	REQUIRE(v1[0] == 5);
	REQUIRE(v1[0] != v2[0]);//because v2 should have its own three slots on the heap, initialized to 0, thanks to the copy constructor
	//this would fail without the copy constructor (see the diagram "Memberwise copy - stack variables") because v2 would point to v1 instead of having
	//its own memory on the heap
}

TEST_CASE("Test overwrite new Vector from an existing Vector instance - check elements")
{
	Vector v3(3);
	Vector v4(3);

	v4 = v3;//overwriting v4 with v3 - using new copy assignment overloaded "=" operator
	v3[0] = 1;

	REQUIRE(v4[0] != v3[0]);//passes because we overloaded the "=" operator in the Vector class.  
	//Although we changed v3, v4 remains unchanged because it has its own memory that it's pointing to
	//Without the overloaded "=" operator, the above test would have failed because after v4=v3 line, 
	//v4 would point to v3's memory, leaving nothing to point to v4's memory, and so we would have no way
	//of deleting v4's memory (causing a memory leak).  See diagram "No copy assignment"
	//With no copy assignment, when program exits, destructor will delete v3 memory and then v4's destructor
	//will run and try to delete memory that doesn't exist (=Bad).
}