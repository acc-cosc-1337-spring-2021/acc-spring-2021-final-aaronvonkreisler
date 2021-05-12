#include "shooter.h"

Shooter::~Shooter(){
  for (auto roll: rolls) {
    delete[] roll;
  }
}

Roll* Shooter::throw_die(Die& die1, Die& die2){
  Roll* roll = new Roll(die1, die2);
  
  roll->roll_die();
  rolls.push_back(std::move(roll));

  return roll;
}

std::ostream& operator<<(std::ostream& out, Shooter& shooter) {
  for (auto roll: shooter.rolls) {
    out<<roll->roll_value()<<"\n";
  }

  return out;
}