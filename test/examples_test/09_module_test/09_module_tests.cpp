#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
//#include "types.h"
#include "ref_pointers.h"

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
