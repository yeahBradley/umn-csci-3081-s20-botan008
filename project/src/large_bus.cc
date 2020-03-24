/**
 * @file large_bus.cc
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#include "src/large_bus.h"

LargeBus::LargeBus(std::string name, Route* out, Route* in, double speed) : 
                                            Bus(name, out, in, BT_LARGE, speed) {
  //Bus::Bus(name, out, in, 90, speed);
}

void LargeBus::Report(std::ostream& out) {
  out << "Bus Type: Large" << std::endl;
  Bus::Report(out);
}
