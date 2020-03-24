/**
 * @file small_bus.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_SMALL_BUS_H_
#define SRC_SMALL_BUS_H_

#include <iostream>

#include "src/bus.h"

class SmallBus : public Bus{
 public:
  SmallBus(std::string name, Route* out, Route* in, double speed);
  void Report(std::ostream&) override;

 private:

};

#endif  // SRC_SMALL_BUS_H_
