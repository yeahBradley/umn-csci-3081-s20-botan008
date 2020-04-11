/**
 * @file i_observer.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_I_OBSERVER_H_
#define SRC_I_OBSERVER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/data_structs.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief IObserver is a pure abstract class intended to observe one bus
 *
 */
class IObserver {
 public:
/**
 * @brief Notify
 *
 * @param[in] BusData info: BusData struct for one bus that is currently being observed
 *
 */
  virtual void Notify(BusData * info) = 0;
};

#endif  // SRC_I_OBSERVER_H_
