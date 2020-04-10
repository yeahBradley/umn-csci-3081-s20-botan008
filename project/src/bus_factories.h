/**
 * @file bus_factories.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_BUS_FACTORIES_H_
#define SRC_BUS_FACTORIES_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/bus_deployment.h"
#include "src/abstract_bus_factory.h"
#include "src/bus_types.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief StrategyBusFactory class that inherits from AbstractBusFactory
 *
 */
class StrategyBusFactory : public AbstractBusFactory{
 public:
/**
 * @brief GenerateBus overrides the virutal function in AbstractBusFactory
 *
 * @param[in] string name: name for the bus
 * @param[in] Route* out: pointer to outbound route
 * @param[in] Route* in: pointer to inbound route
 * @param[in] double speed: speed of bus in time step units
 *
 * @return Pointer to a Bus object, used for derived/base class pointer conversion
 */
  Bus* GenerateBus(std::string name, Route* out, Route* in,
  double speed) override;
};

/**
 * @brief RandomBusFactory class that inherits from AbstractBusFactory
 *
 */
class RandomBusFactory : public AbstractBusFactory{
 public:
/**
 * @brief GenerateBus overrides the virutal function in AbstractBusFactory
 *
 * @param[in] string name: name for the bus
 * @param[in] Route* out: pointer to outbound route
 * @param[in] Route* in: pointer to inbound route
 * @param[in] double speed: speed of bus in time step units
 *
 * @return Pointer to a Bus object, used for derived/base class pointer conversion
 */
  Bus* GenerateBus(std::string name, Route* out, Route* in,
                                    double speed) override;
};

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

#endif  // SRC_BUS_FACTORIES_H_
