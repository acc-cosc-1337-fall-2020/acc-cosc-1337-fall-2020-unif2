#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "if.h"
#include "if_else.h"
#include "switch.h"
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

TEST_CASE("Test menu with switch function")
{
	REQUIRE(menu(1) == "Option 1");
	REQUIRE(menu(2) == "Option 2");
	REQUIRE(menu(10) == "Invalid Option");
	REQUIRE(menu(3) == "Option 3");
	REQUIRE(menu(4) == "Option 4");
}
TEST_CASE("Test menu2 with switch function")
{
	REQUIRE(menu2('a') == "A");
	REQUIRE(menu2('z') == "Invalid Option");
	REQUIRE(menu2('b') == "B");
	REQUIRE(menu2('c') == "C")
}