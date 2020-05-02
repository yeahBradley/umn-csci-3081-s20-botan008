/**
 * @file i_observable.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/i_observable.h"


template<typename T1>// T1 is for data structs type, T2 is for IObservable type
void IObservable<T1>::RegisterObserver(IObservable<T1> observer)    //  (IObserver * observer)
{
  observer_.push_back(observer);
}

template<typename T1>
void IObservable<T1>::ClearObservers() {
  observer_.clear();
}

template<typename T1>
void IObservable<T1>::NotifyObservers(T1 data)  // (BusData * info)
{
  for (typename std::vector<IObservable<T1> >::const_iterator iter = observer_.begin();
  iter != observer_.end(); ++iter) {
    if (*iter != 0) {
      (*iter)->Notify(data);
    }
  }
}
