/**
 * @file i_bus_decorator.h
 * 
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_I_BUS_DECORATOR_H_
#define SRC_I_BUS_DECORATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <iostream>
#include "src/i_bus.h"
/*******************************************************************************
 * Struct Definitions
 ******************************************************************************/
/**
 * @brief IBusDecorator: This is an abstract interface for the bus decorator pattern. All public methods from IBus are included for pass-through.
 * 
 */
class IBusDecorator : public IBus {
 public:
    virtual bool IsTripComplete() = 0;
    virtual bool LoadPassenger(Passenger * pass)  = 0;
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

#endif  // SRC_I_BUS_DECORATOR_H_
