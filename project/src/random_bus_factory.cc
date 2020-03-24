/**
 * @file random_bus_factory.cc
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#include <vector>
#include <random>

#include "src/random_bus_factory.h"

Bus* RandomBusFactory::GenerateBus(std::string name, Route* out, Route* in, double speed) {
    SmallBusFactory smallBusFactory;
    RegularBusFactory regularBusFactory;
    LargeBusFactory largeBusFactory;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);
    int rand_int = dist1(rng);
    
    switch(rand_int) {
        case 1:
            return smallBusFactory.GenerateBus(name, out, in, speed);
        case 2:
            return regularBusFactory.GenerateBus(name, out, in, speed);
        case 3:
            return largeBusFactory.GenerateBus(name, out, in, speed);
        default:
            return regularBusFactory.GenerateBus(name, out, in, speed);
    }

};
