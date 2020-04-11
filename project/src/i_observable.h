/**
 * @file i_observable.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_I_OBSERVABLE_H_
#define SRC_I_OBSERVABLE_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "src/i_observer.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief IObservable allows derived classes to be observable by the IObserver class
 *
 */
class IObservable {
 public:
/**
 * @brief RegisterObserver takes in an observer pointer to be rejistered by the subject
 *
 * @param[in] IObserver* observer: Pointer to an Observer object that is taken in to be registered
 *
 */
  void RegisterObserver(IObserver * observer);
/**
 * @brief ClearObservers removes all the observers that are registered by the subject
 *
 */
  void ClearObservers();
/**
 * @brief NotifyObservers broadcasts BusData to the registered observers
 *
 * @param[in] BusData busData: Pointer to a BusData struct for one bus that contains the data the observers want
 *
 */
  void NotifyObservers(BusData * busData);

 private:
  std::vector<IObserver *> observer_;
};

#endif  // SRC_I_OBSERVABLE_H_
