#include <ctime>
#include <iostream>
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() 
{
	std::srand(time(0));
	Die die1, die2;
	Shooter shooter;
	Roll* roll;

	roll = shooter.throw_die(die1, die2);

	ComeOutPhase come_out_phase;

	while((come_out_phase.get_outcome(roll) == RollOutcome::Natural )|| (come_out_phase.get_outcome(roll) == RollOutcome::Craps)) {
		std::cout<<roll->roll_value()<<"\n";
		std::cout<<"Roll again \n";
		roll = shooter.throw_die(die1, die2);
	}

// Display rolled value with the text start of point phase
	std::cout<<"Rolled "<<roll->roll_value()<<" start of point phase\n";
// Display the text Roll until rolled value or 7 is rolled. 
	std::cout<<"Roll until "<<roll->roll_value()<<" or 7 is rolled \n";

	// Create an int point variable set to roll rolled_value 
	int point = roll->roll_value();

	// Set roll equal to the return value of the shooter throw_die function
	roll = shooter.throw_die(die1, die2);

	// Create an instance of PointPhase point_phase
	PointPhase point_phase(point);

	// Create a loop that continues while point_phase get_outcome is RollOutcome::point or  RollOutcome::notpoint
	   // In loop code
		   // Display the rolled value and the text roll again    
			// Set roll equal to the return value of the shooter throw_die function
	
	while((point_phase.get_outcome(roll) == RollOutcome::Point) || (point_phase.get_outcome(roll) == RollOutcome::NoPoint)) {
		std::cout<<"Rolled "<<roll->roll_value()<<" roll again\n";
		roll = shooter.throw_die(die1, die2);
	}

	// Display rolled value and the text end of point phase
	std::cout<<"Rolled "<<roll->roll_value()<<" end of point phase\n";
	// Use cout to display the shooter variable
	std::cout<<shooter;

	return 0;
}