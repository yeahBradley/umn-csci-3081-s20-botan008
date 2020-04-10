/**
 * @file i_observable.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include <vector>
#include "src/i_observer.h"

class IObservable {
public:
  void RegisterObserver(IObserver * observer);
  void ClearObservers();
  void NotifyObservers(BusData * busData);

private:
  std::vector<IObserver *> observer_;
};
