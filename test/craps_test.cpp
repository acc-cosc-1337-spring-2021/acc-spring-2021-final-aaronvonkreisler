#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <ctime>
#include <iostream>

#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

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

TEST_CASE("shooter returns a Roll and the roll result has one of the following values: 2-12") {
	std::srand(time(0));
	Die die1, die2;
	Shooter shooter;
	Roll* value;

	for (int i=0; i < 10; ++i) {
	  value = shooter.throw_die(die1, die2);
		REQUIRE(((value->roll_value() > 1) && (value->roll_value() < 13)));
	}
}

TEST_CASE("Test ComeOutPhase get_outcomes returns correct values") {
	std::srand(time(0));
	Die die1, die2;
	Roll roll(die1, die2);
	Roll* rollptr = &roll;
	ComeOutPhase comeout;
	RollOutcome value;

	for (int i = 0; i < 10; ++i) {
		value = comeout.get_outcome(rollptr);
		REQUIRE(((value == RollOutcome::Natural) || (value == RollOutcome::Point)|| (value == RollOutcome::Craps)));
		REQUIRE((value == RollOutcome::Seven_Out) == false);
		REQUIRE((value == RollOutcome::NoPoint) == false);
	}


}

TEST_CASE("Test PointPhase get_outcomes returns correct values") {
	std::srand(time(0));
	Die die1, die2;
	Roll roll(die1, die2);
	Roll* rollptr = &roll;
	PointPhase Point(0);
	RollOutcome value;

	for (int i =0; i < 10; ++i) {
		value = Point.get_outcome(rollptr);

		REQUIRE(((value == RollOutcome::Point) || (value == RollOutcome::Seven_Out) || (value == RollOutcome::NoPoint)));
		REQUIRE((value == RollOutcome::Craps) == false);
		REQUIRE((value == RollOutcome::Natural) == false);
	}

}
