/**
 * @file small_bus.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_SMALL_BUS_H_
#define SRC_SMALL_BUS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include "src/bus.h"
/**
 * @brief The SmallBus class is a derived class of Bus
 *
 */
class SmallBus : public Bus{
 public:
 /**
  * @brief The SmallBus constructor
  *
  * @param[in] string name: name for the bus
  * @param[in] Route* out: pointer to outbound route
  * @param[in] Route* in: pointer to inbound route
  * @param[in] double speed: speed of bus in time step units
  *
  * @return pointer to a LargeBus object
  */
  SmallBus(std::string name, Route* out, Route* in, double speed);
 /**
  * @brief Report overides the Bus::Report() method to include output that specifies the type of Bus
  *
  * @param[in] ostream&: a reference to an ostream object for printing
  */
  void Report(std::ostream&) override;
};

#endif  // SRC_SMALL_BUS_H_
