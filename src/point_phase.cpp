#include "point_phase.h"

RollOutcome PointPhase::get_outcome(Roll* roll) {
  int value = roll->roll_value();

  if (value == point) {
    return RollOutcome::Point;
  }

  if (value == 7) {
    return RollOutcome::Seven_Out;
  }

  return RollOutcome::NoPoint;
  
}