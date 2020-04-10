/**
 * @file bus_deployment.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_BUS_DEPLOYMENT_H_
#define SRC_BUS_DEPLOYMENT_H_

#include "src/bus.h"

class BusDeployment {
public:
  virtual int execute() = 0;
};

class MorningStrategy : public BusDeployment {
public:
  int execute() override;
};

class AfternoonStrategy : public BusDeployment {
public:
  int execute() override;
};

class EveningStrategy : public BusDeployment {
public:
  int execute() override;
};

class OvernightStrategy : public BusDeployment {
public:
  int execute() override;
};
#endif  // SRC_BUS_DEPLOYMENT_H_
