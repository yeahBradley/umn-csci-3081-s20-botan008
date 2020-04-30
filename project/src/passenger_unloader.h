/**
 * @file passenger_unloader.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_UNLOADER_H_
#define SRC_PASSENGER_UNLOADER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <string>
#include "src/passenger.h"
#include "src/stop.h"
#include "src/file_writer.h"
/*******************************************************************************
 * Forward Declarations
 ******************************************************************************/
class Stop;
class Passenger;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class PassengerUnloader {
 public:
  /**
   * @brief UnloadPassengers: Removes passengers from the bus and sends passenger log data to the singleton File Writer
   *
   * @param[in] std::list<Passenger*>* passengers: Pointer to list of passengers on the bus
   * @param[in] Stop * current_stop: Pointer to current stop.
   * 
   * @return int: returns the number of passengers removed from the bus.
   */
  int UnloadPassengers(std::list<Passenger*>* passengers, Stop * current_stop);

 private:
  std::string passenger_stats_file_name_ = "PassData.csv";
};
#endif  // SRC_PASSENGER_UNLOADER_H_
