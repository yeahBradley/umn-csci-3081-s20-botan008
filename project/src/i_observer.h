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
template <typename T>
class IObserver {
 public:
/**
 * @brief Notify
 *
 * @param[in] T info: A struct (either BusData or StopData) for one bus or stop that is currently being observed
 *
 */
  virtual void Notify(T info) = 0;
};

#endif  // SRC_I_OBSERVER_H_
