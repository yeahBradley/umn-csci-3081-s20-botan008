/**
 * @file regular_bus.cc
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#include "src/regular_bus.h"

RegularBus::RegularBus(std::string name, Route* out, Route* in, double speed) :
                                       Bus(name, out, in, BT_REGULAR, speed) {}

void RegularBus::Report(std::ostream& out) {
  out << "Bus Type: Regular" << std::endl;
  Bus::Report(out);
}
