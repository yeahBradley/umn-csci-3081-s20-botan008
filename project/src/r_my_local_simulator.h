/**
 * @file r_my_local_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_R_MY_LOCAL_SIMULATOR_H_
#define SRC_R_MY_LOCAL_SIMULATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include "src/r_simulator.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief This class emulates visualization simulator for the purposes of my regression test.
*
*/
class rMyLocalSimulator : public rSimulator {
 public:
/**
 * @brief Begins the simulation by creating the stops, routes, and busses needed.
 *
 * @return bool: This return type isn't strictly necessary as the method cannot return false, but is kept as legacy with the given regression test.
 *
 */
  bool Start() override;
/**
 * @brief Updates all the components (stops, busses, routes, etc.) of the simulation one after the other.
 *
 * @return bool: This return type isn't strictly necessary as the method cannot return false, but is kept as legacy with the given regression test.
 *
 */
  bool Update() override;
 private:
  std::vector<int> bus_counters_;
  std::vector<int> bus_start_timings_;
  std::vector<int> time_since_last_bus_generation_;
  int simulation_time_elapsed_;
};

#endif  // SRC_R_MY_LOCAL_SIMULATOR_H_
