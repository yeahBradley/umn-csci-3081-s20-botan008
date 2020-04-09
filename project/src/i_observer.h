/**
 * @file i_observer.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/data_structs.h"

class IObserver {
 public:
  virtual void UpdateObserver(BusData * info) = 0;
}
