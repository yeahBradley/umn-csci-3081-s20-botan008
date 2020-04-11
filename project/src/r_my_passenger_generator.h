/**
 * @file r_my_passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_R_MY_PASSENGER_GENERATOR_H_
#define SRC_R_MY_PASSENGER_GENERATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <random>
#include <ctime>
#include "src/passenger_generator.h"
#include "src/stop.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Stop;  // forward declaration
/**
* @brief This class emulates the passenger generator used in the main program for the purposes of my regression test.
*
* This passenger generator produces (stop_id + 1) passengers for each stop at every generate phase.
*
*/
class rMyPassengerGenerator : public PassengerGenerator{
 public:
   /**
   * @brief Specialized constructor for my regression test.
   *
   */
  rMyPassengerGenerator(std::list<double>, std::list<Stop *>);
  /**
  * @brief Overrides the function from the Passenger Generator class.
  *
  * @return Returns an int that is the number of passengers generated during one generate phase.
  *
  */
  int GeneratePassengers() override;

 private:
  static std:: minstd_rand0 my_rand;
};

#endif  // SRC_R_MY_PASSENGER_GENERATOR_H_
