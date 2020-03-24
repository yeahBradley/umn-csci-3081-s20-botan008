/**
 * @file regular_bus_factory.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_REGULAR_BUS_FACTORY_H_
#define SRC_REGULAR_BUS_FACTORY_H_

#include "src/abstract_bus_factory.h"
#include "src/regular_bus.h"

class RegularBusFactory : public AbstractBusFactory{
 public:
  RegularBus* GenerateBus(std::string name, Route* out, Route* in, double speed) override;
 private:

};

#endif  // SRC_REGULAR_BUS_FACTORY_H_