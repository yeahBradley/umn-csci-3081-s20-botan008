/**
 * @file large_bus_factory.cc
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#include "src/large_bus_factory.h"

LargeBus* LargeBusFactory::GenerateBus(std::string name, Route* out, Route* in,
                                                             double speed) {
    LargeBus *bus1;
    bus1 = new LargeBus(name, out, in, speed);
    return bus1;
}
