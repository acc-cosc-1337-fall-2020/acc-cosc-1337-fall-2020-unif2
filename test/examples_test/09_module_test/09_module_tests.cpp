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

TEST_CASE("Test create vector from existing vector instance - compare size")
{
	Vector v1(3);
	Vector v2 = v1;

	REQUIRE(v1.Size() == v2.Size());
}

TEST_CASE("Test create vector from existing vector instance - compare elements")
{
	Vector v1(3);
	Vector v2 = v1;//v2's elements points to same elements array as v1

	v1[0] = 5;
	REQUIRE(v1[0] == 5);//
	REQUIRE(v1[0] != v2[0]);
}

TEST_CASE("Test create vector by overwriting existing vector with existing vector instance")
{
	Vector v3(3);
	Vector v4(3);

	v3[0] = 1;
	v4 = v3;

	REQUIRE(v3[0] == v4[0]);
}