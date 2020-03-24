/**
 * @file small_bus_factory.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_SMALL_BUS_FACTORY_H_
#define SRC_SMALL_BUS_FACTORY_H_

#include <string>

#include "src/abstract_bus_factory.h"
#include "src/small_bus.h"

class SmallBusFactory : public AbstractBusFactory{
 public:
  SmallBus* GenerateBus(std::string name, Route* out, Route* in,
                                         double speed) override;
 private:
};

#endif  // SRC_SMALL_BUS_FACTORY_H_
