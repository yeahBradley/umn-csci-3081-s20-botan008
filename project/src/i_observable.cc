/**
 * @file i_observable.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/i_observable.h"

void IObservable::RegisterObserver(IObserver * observer) {
  observer_.push_back(observer);
}

void IObservable::ClearObservers() {
  observer_.erase(std::remove(observer_.begin(), observer_.end(), observer), list.end());
}

void IObservable::NotifyObservers(IObserver * ) {
  for(vector<IObserver *>::const_iterator iter = observer_.begin(); iter != observer.end(); ++iter) {
    if(*iter != 0) {
      (*iter)->UpdateObserver(&bus_data_);
    }
  }
}
