#ifndef SHOOTER_H
#define SHOOTER_H
#include <iostream>
#include <vector>
#include "roll.h"

class Shooter {
  private:
    std::vector<Roll*> rolls;
  public:
    ~Shooter();
    Roll* throw_die(Die& die1, Die& die2);
    friend std::ostream& operator<<(std::ostream& out, Shooter& shooter);


};

#endif