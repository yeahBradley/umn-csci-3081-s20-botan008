/**
 * @file i_observer.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_I_OBSERVER_H_
#define SRC_I_OBSERVER_H_

#include "src/data_structs.h"

class IObserver {
 public:
  virtual void Notify(BusData * info) = 0;
};

#endif  // SRC_I_OBSERVER_H_
