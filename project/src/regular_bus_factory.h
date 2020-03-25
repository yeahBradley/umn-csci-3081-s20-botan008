/**
 * @file regular_bus_factory.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_REGULAR_BUS_FACTORY_H_
#define SRC_REGULAR_BUS_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/abstract_bus_factory.h"
#include "src/regular_bus.h"

/**
 * @brief RegularBusFactory class that inherits from AbstractBusFactory
 *
 */
class RegularBusFactory : public AbstractBusFactory{
 public:
 /**
  * @brief GenerateBus overrides the virutal function in AbstractBusFactory
  *
  * @param[in] string name: name for the bus
  * @param[in] Route* out: pointer to outbound route
  * @param[in] Route* in: pointer to inbound route
  * @param[in] double speed: speed of bus in time step units
  *
  * @return pointer to a RegularBus object
  */
  RegularBus* GenerateBus(std::string name, Route* out, Route* in,
                                             double speed) override;
};

#endif  // SRC_REGULAR_BUS_FACTORY_H_
