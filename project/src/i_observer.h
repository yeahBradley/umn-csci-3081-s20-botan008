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
 * @brief IObserver: A template class that is intended to use busdata structs and stopdata structs.
 *
 */
template<typename T1>
class IObserver {
 public:
/**
 * @brief Notify
 *
 * @param[in] theType* info: theType could be a busdata struct or stopdata struct
 *
 */
  virtual void Notify(T1* data) = 0;
};

#endif  // SRC_I_OBSERVER_H_
