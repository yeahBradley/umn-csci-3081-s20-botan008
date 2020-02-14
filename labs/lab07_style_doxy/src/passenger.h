/**
 * @file passenger.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef PASSENGER_H
#define PASSENGER_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the passenger object.
 * 
 * 
 */
class Passenger { // : public Reporter {
 public:
 /**
  * @brief Constructor Passenger()
  * 
  * Methods: Update(), GetOnBus(), GetTotalWait(), 
  * 
  */
  Passenger(int = -1, std::string = "Nobody");
  /**
   * @brief Update() method
   * 
   */
  void Update();
  /**
   * @brief GetonBus() method
   * 
   */
  void GetOnBus();
  /**
   * @brief GetTotalWait() const method
   * 
   */
  int GetTotalWait() const;
  /**
   * @brief IsOnBus() const method
   * 
   */
  bool IsOnBus() const;
  /**
   * @brief GetDestination() const method
   * 
   */
  int GetDestination() const;
  /**
   * @brief Report() const method
   * 
   */
  void Report() const;
 private:
 /**
  * @brief private member variables
  * 
  * 
  */
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances
  
};
#endif