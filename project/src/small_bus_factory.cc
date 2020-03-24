/**
 * @file small_bus_factory.cc
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#include "src/small_bus_factory.h"

SmallBus* SmallBusFactory::GenerateBus(std::string name, Route* out, Route* in,
                                                             double speed) {
    SmallBus *bus1;
    bus1 = new SmallBus(name, out, in, speed);
    return bus1;
}
