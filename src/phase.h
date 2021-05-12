#ifndef PHASE_H
#define PHASE_H
#include "roll.h"


enum class RollOutcome {Natural, Craps, Point, Seven_Out, NoPoint};

class Phase {
  public:
     virtual RollOutcome get_outcome(Roll* roll) = 0;
};

#endif