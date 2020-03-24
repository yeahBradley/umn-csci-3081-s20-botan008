/**
 * @file large_bus_factory.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_LARGE_BUS_FACTORY_H_
#define SRC_LARGE_BUS_FACTORY_H_

#include <string>

#include "src/abstract_bus_factory.h"
#include "src/large_bus.h"

class LargeBusFactory : public AbstractBusFactory{
 public:
  LargeBus* GenerateBus(std::string name, Route* out, Route* in,
                                         double speed) override;
 private:
};

#endif  // SRC_LARGE_BUS_FACTORY_H_
