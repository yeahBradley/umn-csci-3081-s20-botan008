/**
 * @file r_my_passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_R_MY_PASSENGER_GENERATOR_H_
#define SRC_R_MY_PASSENGER_GENERATOR_H_

#include <list>
#include <random>
#include <ctime>

#include "src/passenger_generator.h"
#include "src/stop.h"

class Stop;  // forward declaration

class rMyPassengerGenerator : public PassengerGenerator{
 public:
  rMyPassengerGenerator(std::list<double>, std::list<Stop *>);
  int GeneratePassengers() override;

 private:
  static std:: minstd_rand0 my_rand;
};

#endif  // SRC_R_MY_PASSENGER_GENERATOR_H_
