/**
 * @file regular_bus.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_REGULAR_BUS_H_
#define SRC_REGULAR_BUS_H_

#include <iostream>
#include <string>

#include "src/bus.h"

class RegularBus : public Bus{
 public:
  RegularBus(std::string name, Route* out, Route* in, double speed);
  void Report(std::ostream&) override;

 private:
};

#endif  // SRC_REGULAR_BUS_H_
