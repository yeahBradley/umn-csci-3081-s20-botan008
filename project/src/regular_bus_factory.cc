/**
 * @file regular_bus_factory.cc
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#include "src/regular_bus_factory.h"

RegularBus* RegularBusFactory::GenerateBus(std::string name, Route* out, Route* in, double speed) {
    RegularBus *bus1;
    bus1 = new RegularBus(name, out, in, speed);
    return bus1;

};
