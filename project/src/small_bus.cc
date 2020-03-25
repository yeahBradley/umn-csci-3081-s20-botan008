/**
 * @file small_bus.cc
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#include "src/small_bus.h"

SmallBus::SmallBus(std::string name, Route* out, Route* in, double speed) :
                                         Bus(name, out, in, BT_SMALL, speed) {}

void SmallBus::Report(std::ostream& out) {
  out << "Bus Type: Small" << std::endl;
  Bus::Report(out);
}