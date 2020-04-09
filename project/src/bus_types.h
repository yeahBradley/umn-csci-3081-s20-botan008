/**
 * @file bus_types.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_BUS_TYPES_H_
#define SRC_BUS_TYPES_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include "src/bus.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
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

/**
 * @brief The RegularBus class is a derived class of Bus
 *
 */
class RegularBus : public Bus{
 public:
/**
 * @brief The RegularBus constructor
 *
 * @param[in] string name: name for the bus
 * @param[in] Route* out: pointer to outbound route
 * @param[in] Route* in: pointer to inbound route
 * @param[in] double speed: speed of bus in time step units
 *
 * @return pointer to a LargeBus object
 */
    RegularBus(std::string name, Route* out, Route* in, double speed);
/**
 * @brief Report overides the Bus::Report() method to include output that specifies the type of Bus
 *
 * @param[in] ostream&: a reference to an ostream object for printing
 */
    void Report(std::ostream&) override;
};

/**
 * @brief The LargeBus class is a derived class of Bus
 *
 */
class LargeBus : public Bus{
 public:
/**
 * @brief The LargeBus constructor
 *
 * @param[in] string name: name for the bus
 * @param[in] Route* out: pointer to outbound route
 * @param[in] Route* in: pointer to inbound route
 * @param[in] double speed: speed of bus in time step units
 *
 * @return pointer to a LargeBus object
 */
  LargeBus(std::string name, Route* out, Route* in, double speed);
/**
 * @brief Report overides the Bus::Report() method to include output that specifies the type of Bus
 *
 * @param[in] ostream&: a reference to an ostream object for printing
 */
  void Report(std::ostream&) override;
};


#endif  // SRC_BUS_TYPES_H_
