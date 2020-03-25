/**
 * @file small_bus_factory.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_SMALL_BUS_FACTORY_H_
#define SRC_SMALL_BUS_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/abstract_bus_factory.h"
#include "src/small_bus.h"

/**
 * @brief SmallBusFactory class that inherits from AbstractBusFactory
 *
 */
class SmallBusFactory : public AbstractBusFactory{
 public:
 /**
  * @brief GenerateBus overrides the virutal function in AbstractBusFactory
  *
  * @param[in] string name: name for the bus
  * @param[in] Route* out: pointer to outbound route
  * @param[in] Route* in: pointer to inbound route
  * @param[in] double speed: speed of bus in time step units
  *
  * @return pointer to a SmallBus object
  */
  SmallBus* GenerateBus(std::string name, Route* out, Route* in,
                                         double speed) override;
};

#endif  // SRC_SMALL_BUS_FACTORY_H_
