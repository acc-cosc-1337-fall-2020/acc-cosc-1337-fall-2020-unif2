#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "if.h"
#include "if_else.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test if even function"){
	REQUIRE(is_even(5)==false);
	REQUIRE(is_even(4) == true);
}
TEST_CASE("Test overtime"){
	REQUIRE(overtime(30)==false);
	REQUIRE(overtime(40)==false);
	REQUIRE(overtime(42)==true);
}

TEST_CASE("Test get generation function")
{
	REQUIRE(get_generation(2000)=="Centenial");
	REQUIRE(get_generation(1600)=="Invalid Year");
	REQUIRE(get_generation(1980)=="Millenial");
}
