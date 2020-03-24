/**
 * @file abstract_bus_factory.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_ABSTRACT_BUS_FACTORY_H_
#define SRC_ABSTRACT_BUS_FACTORY_H_

#include <string>

#include "src/bus.h"

class AbstractBusFactory {
 public:
  // AbstractBusFactory();
  // Makes the class abstract, cannot instantiate and forces subclass override
  virtual Bus* GenerateBus(std::string name, Route* out, Route* in,
                                                 double speed) = 0;
 protected:
};
#endif  // SRC_ABSTRACT_BUS_FACTORY_H_
