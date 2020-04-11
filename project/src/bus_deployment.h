/**
 * @file bus_deployment.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_BUS_DEPLOYMENT_H_
#define SRC_BUS_DEPLOYMENT_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/bus.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Bus Deployment is a pure abstract class for the Bus Depot strategies
 *
 */
class BusDeployment {
 public:
/**
 * @brief Execute is a pure virtual method
 *
 * @return An int that specifies the type of bus to be deployed.
 *
 */
  virtual int execute() = 0;
};
/**
 * @brief Morning Strategy is for deploying busses between 6am and 8am
 *
 */
class MorningStrategy : public BusDeployment {
 public:
/**
 * @brief Execute overrides the virtual method in BusDeployment and it performs the specified classes strategy
 *
 * @return An int that specifies the type of bus to be deployed.
 *
 */
  int execute() override;
};
/**
 * @brief Afternoon Strategy is for deploying busses between 8am and 3pm
 *
 */
class AfternoonStrategy : public BusDeployment {
 public:
/**
 * @brief Execute overrides the virtual method in BusDeployment and it performs the specified classes strategy
 *
 * @return An int that specifies the type of bus to be deployed.
 *
 */
  int execute() override;
};
/**
 * @brief Evening Strategy is for deploying busses between 3pm and 8pm
 *
 */
class EveningStrategy : public BusDeployment {
 public:
/**
 * @brief Execute overrides the virtual method in BusDeployment and it performs the specified classes strategy
 *
 * @return An int that specifies the type of bus to be deployed.
 *
 */
  int execute() override;
};
/**
 * @brief Overnight Strategy is for deploying busses between 8pm and 6am
 *
 */
class OvernightStrategy : public BusDeployment {
 public:
/**
 * @brief Execute overrides the virtual method in BusDeployment and it performs the specified classes strategy
 *
 * @return An int that specifies the type of bus to be deployed.
 *
 */
  int execute() override;
};
#endif  // SRC_BUS_DEPLOYMENT_H_
