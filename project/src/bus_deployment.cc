/**
 * @file bus_deployment.cc
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#include "src/bus_deployment.h"

// 6am or later but before 8am
int MorningStrategy::execute() {
  static int strategyLevel = 0;
  strategyLevel++;
  switch (strategyLevel %= 2) {
    case 0:
      return BT_SMALL;
    case 1:
      return BT_REGULAR;
    default:
      return BT_LARGE;
  }
}

// 8am or later but before 3pm
int AfternoonStrategy::execute() {
  static int strategyLevel = 0;
  strategyLevel++;
  switch (strategyLevel %= 2) {
    case 0:
      return BT_REGULAR;
    case 1:
      return BT_LARGE;
    default:
      return BT_SMALL;
  }
}

// 3pm or later but before 8pm
int EveningStrategy::execute() {
  static int strategyLevel = -1;
  strategyLevel++;
  switch (strategyLevel %= 3) {
    case 0:
      return BT_SMALL;
    case 1:
      return BT_REGULAR;
    case 2:
      return BT_LARGE;
    default:
      return BT_SMALL;
  }
}

// 8pm or later but before 6am
int OvernightStrategy::execute() {
  return BT_SMALL;
}
