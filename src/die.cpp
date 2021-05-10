#include "die.h"
#include <iostream>

void Die::roll() {
  roll_value = (rand() % 6) + 1;
}

int Die::rolled_value(){
  return roll_value;
}