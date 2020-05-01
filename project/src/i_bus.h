/**
 * @file i_bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_I_BUS_H_
#define SRC_I_BUS_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/i_observable.h"
#include "src/data_structs.h"
#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief IBus : Interface for the bus class so that bus decorators can also be the same type.
 */
class IBus : public IObservable {
 public:
    virtual bool IsTripComplete() = 0;
    virtual bool LoadPassenger(Passenger * pass) = 0;
    virtual bool IsOutgoingRouteComplete() = 0;
    virtual void SetColor(Color color) = 0;
    virtual bool Move() = 0;
    virtual void Update() = 0;
    virtual void Report(std::ostream& ostr) = 0;
    virtual void UpdateBusData() = 0;
    virtual BusData GetBusData() const = 0;
    virtual std::string GetName() const = 0;
    virtual Stop * GetNextStop() const = 0;
    virtual size_t GetNumPassengers() const = 0;
    virtual int GetCapacity() const = 0;

 private:
};

 #endif  // SRC_I_BUS_H
