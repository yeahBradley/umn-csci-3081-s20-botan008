/**
 * @file random_bus_factory.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_RANDOM_BUS_FACTORY_H_
#define SRC_RANDOM_BUS_FACTORY_H_

#include <string>

#include "src/abstract_bus_factory.h"
#include "src/small_bus_factory.h"
#include "src/regular_bus_factory.h"
#include "src/large_bus_factory.h"

class RandomBusFactory : public AbstractBusFactory{
 public:
  Bus* GenerateBus(std::string name, Route* out, Route* in,
                                     double speed) override;
 private:
};

#endif  // SRC_RANDOM_BUS_FACTORY_H_
