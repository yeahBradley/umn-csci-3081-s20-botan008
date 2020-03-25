/**
 * @file large_bus_factory.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_LARGE_BUS_FACTORY_H_
#define SRC_LARGE_BUS_FACTORY_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/abstract_bus_factory.h"
#include "src/large_bus.h"

/**
 * @brief LargeBusFactory class that inherits from AbstractBusFactory
 *
 */
class LargeBusFactory : public AbstractBusFactory{
 public:
 /**
  * @brief GenerateBus overrides the virutal function in AbstractBusFactory
  *
  * @param[in] string name: name for the bus
  * @param[in] Route* out: pointer to outbound route
  * @param[in] Route* in: pointer to inbound route
  * @param[in] double speed: speed of bus in time step units
  *
  * @return pointer to a LargeBus object
  */
  LargeBus* GenerateBus(std::string name, Route* out, Route* in,
                                         double speed) override;
};

#endif  // SRC_LARGE_BUS_FACTORY_H_
