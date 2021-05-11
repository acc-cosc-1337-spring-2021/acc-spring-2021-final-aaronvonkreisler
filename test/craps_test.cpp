#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <ctime>
#include <iostream>

#include "catch.hpp"
#include "die.h"
#include "roll.h"


TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify die roll returns a value from 1 to 6") {
	std::srand(time(0));
	Die die;

	for (int i = 0; i < 10; ++i) {
		die.roll();
		int value = die.rolled_value();
		REQUIRE(((value > 0) && (value < 7)));
	}
}

TEST_CASE("Assert die rolls return a value from 2 to 12"){
	std::srand(time(0));
	Die die1, die2;

	Roll roll(die1, die2);

	for (int i = 0; i < 10; ++i) {
		roll.roll_die();
		int val = roll.roll_value();
		REQUIRE(((val > 1) && (val < 13)));
	}
}
