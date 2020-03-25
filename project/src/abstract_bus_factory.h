/**
 * @file abstract_bus_factory.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_ABSTRACT_BUS_FACTORY_H_
#define SRC_ABSTRACT_BUS_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/bus.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief AbstractBusFactory is a pure abstract Class
 */
class AbstractBusFactory {
 public:
   /**
   * @brief GenerateBus is a pure virtual method
   *
   * @param[in] string name: name for the bus
   * @param[in] Route* out: pointer to outbound route
   * @param[in] Route* in: pointer to inbound route
   * @param[in] double speed: speed of bus in time step units
   *
   * @return pointer to a Bus object
   */
  virtual Bus* GenerateBus(std::string name, Route* out, Route* in,
                                                 double speed) = 0;
};
#endif  // SRC_ABSTRACT_BUS_FACTORY_H_
