// support class cpp file

#include "tools/sup.h"

#include <cmath>

using namespace std;

int rightRound(const double num) {
  return static_cast<int>(num < 0 ? num - 0.5 : num + 0.5);
}

double deg2rad(const double a) {
  /*
  180 - pi
  a   - x
  */
  return (M_PI * a) / 180.0;
}