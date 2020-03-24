/**
 * @file large_bus.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_LARGE_BUS_H_
#define SRC_LARGE_BUS_H_

#include <iostream>
#include <string>

#include "src/bus.h"

class LargeBus : public Bus{
 public:
  LargeBus(std::string name, Route* out, Route* in, double speed);
  void Report(std::ostream&) override;

 private:
};

#endif  // SRC_LARGE_BUS_H_
