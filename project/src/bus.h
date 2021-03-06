/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 *
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

#include <iostream>
#include <list>
#include <string>


#include "src/i_bus.h"
#include "src/data_structs.h"
#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

enum BusType {
  BT_SMALL = 30, BT_REGULAR = 60, BT_LARGE = 90
};

class Bus : public IBus {
 public:
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                                 double speed = 1);
  bool IsTripComplete();
  /**
   * @brief LoadPassenger: Load's a passenger onto the bus from the stop. Now keeps count of the passengers added.
   * 
   * @param[in] Passenger * : pointer to a single passenger object that will be loaded onto the bus
   * 
   * @return bool: the bool flag communicates whether a passenger was successfully added to the bus
   */
  bool LoadPassenger(Passenger * pass);  // returning revenue delta
  /**
   * @brief IsOutgoingRouteComplete: Checks if the outgoing has been completed
   * 
   * @return bool: The return type is a boollean flag.
   */
  bool IsOutgoingRouteComplete();
  /**
   * @brief SetBusData: This, along with the preexisting GetBusData is what allows the BusColorDecorator to change the color.
   */
  void SetBusData(BusData newBusData);
  bool Move();
  void Update();
  void Report(std::ostream&);

  // Vis Getters
  void UpdateBusData();
  BusData GetBusData() const;
  std::string GetName() const { return name_; }
  Stop * GetNextStop() const { return next_stop_; }
  size_t GetNumPassengers() const { return passengers_.size(); }
  int GetCapacity() const { return passenger_max_capacity_; }

 private:
  int UnloadPassengers();  // returning revenue delta
  // bool Refuel();
  PassengerUnloader * unloader_;
  PassengerLoader * loader_;
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
  std::string name_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                              // AND next stop set
  Stop * next_stop_;
  // bool trip_complete_;  // [DERIVED data] when BOTH routes are at end, trip
  // is complete

  // Vis data for bus
  BusData bus_data_;

  int total_num_of_passengers_;
};
#endif  // SRC_BUS_H_
