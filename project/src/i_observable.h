/**
 * @file i_observable.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include <vector>

class IObservable {
public:
  void RegisterObserver (IObserver * observer);
  void ClearObserver();
  void NotifyObservers(IObserver * );

private:
  vector<IObserver *> observer_;
}
