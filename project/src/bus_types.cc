/**
 * @file bus_types.cc
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#include "src/bus_types.h"

LargeBus::LargeBus(std::string name, Route* out, Route* in, double speed) :
                                     Bus(name, out, in, BT_LARGE, speed) {}

void LargeBus::Report(std::ostream& out) {
  out << "Bus Type: Large" << std::endl;
  Bus::Report(out);
}

RegularBus::RegularBus(std::string name, Route* out, Route* in, double speed) :
                                       Bus(name, out, in, BT_REGULAR, speed) {}

void RegularBus::Report(std::ostream& out) {
  out << "Bus Type: Regular" << std::endl;
  Bus::Report(out);
}

SmallBus::SmallBus(std::string name, Route* out, Route* in, double speed) :
                                         Bus(name, out, in, BT_SMALL, speed) {}

void SmallBus::Report(std::ostream& out) {
  out << "Bus Type: Small" << std::endl;
  Bus::Report(out);
}
