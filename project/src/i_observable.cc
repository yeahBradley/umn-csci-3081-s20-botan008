/**
 * @file i_observable.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <iostream>

#include "src/i_observable.h"
template <typename T>
void IObservable<T>::RegisterObserver(IObserver<T> * observer) {
  observer_.push_back(observer);
}
template <typename T>
void IObservable<T>::ClearObservers() {
  observer_.clear();
}
template <typename T>
void IObservable<T>::NotifyObservers(T info) {
  for (typename std::vector<IObserver<T> *>::const_iterator iter =
                                                observer_.begin();
  iter != observer_.end(); ++iter) {
    if (*iter != 0) {
      (*iter)->Notify(info);
    }
  }
}

template class IObservable<BusData*>;
template class IObservable<StopData*>;
