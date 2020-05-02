/**
 * @file i_observable.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <iostream>

#include "src/i_observable.h"
template <typename T>
void IObservable<T>::RegisterObserver(IObserver<T> * observer) {
  std::cout << "                " << std::endl;
  std::cout << "                " << std::endl;
  std::cout << "                " << std::endl;
  std::cout << "                INSIDE IObservable::RegisterObserver" << std::endl;
  observer_.push_back(observer);
  std::cout << "                observer_.size() is : " << observer_.size() << std::endl;
}
template <typename T>
void IObservable<T>::ClearObservers() {
  std::cout << "                " << std::endl;
  std::cout << "                " << std::endl;
  std::cout << "                " << std::endl;
  std::cout << "                INSIDE IObservable::ClearObservers" << std::endl;
  observer_.clear();
}
template <typename T>
void IObservable<T>::NotifyObservers(T info) {
  std::cout << "                " << std::endl;
  std::cout << "                " << std::endl;
  std::cout << "                " << std::endl;
  std::cout << "                INSIDE IObservable::NotifyObservers" << std::endl;
  std::cout << "                observer_.size() is : " << observer_.size() << std::endl;
  for (typename std::vector<IObserver<T> *>::const_iterator iter = observer_.begin();
  iter != observer_.end(); ++iter) {
    std::cout << "                INSIDE IObservable::NotifyObservers:  for loop" << std::endl;
    if (*iter != 0) {
      std::cout << "                INSIDE IObservable::NotifyObservers: if statement" << std::endl;
      (*iter)->Notify(info);
    }
  }
}

template class IObservable<BusData*>;
template class IObservable<StopData*>;