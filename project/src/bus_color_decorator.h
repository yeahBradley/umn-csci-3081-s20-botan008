/**
 * @file bus_color_decorator.h
 * 
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_BUS_COLOR_DECORATOR_H_
#define SRC_BUS_COLOR_DECORATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/i_bus_decorator.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief BusColorDecorator: A concrete class of the bus decorator interface. All the methods save SetColor and Update are simple pass-through methods to the base class object wrapped_bus_.
 */
class BusColorDecorator : public IBusDecorator {
 protected:
    Bus *wrapped_bus_;

 public:
    /**
     * @brief BusColorDecorator : The constructor for this decorator class only needs to store the base class object it was given.
     * 
     * @param[in] Bus* baseBus : pointer to the base bus object that will be decorated by this class
     */
    BusColorDecorator(Bus* baseBus) : wrapped_bus_(baseBus) {}
    
    bool IsTripComplete() {return wrapped_bus_->IsTripComplete();}
    bool LoadPassenger(Passenger* pass) {return wrapped_bus_->LoadPassenger(pass);}
    bool IsOutgoingRouteComplete() {return wrapped_bus_->IsOutgoingRouteComplete();}
    /**
     * @brief SetColor: The decorator uses this method to change the color of its base bus
     */
    void SetColor(Color color) {
        Color maroon{178,34,34,255};
        Color gold{197,179,88,255};

        if (wrapped_bus_->IsOutgoingRouteComplete()) {
            wrapped_bus_->SetColor(gold);
        } else {
            wrapped_bus_->SetColor(maroon);
        }   
    }
    bool Move() {return wrapped_bus_->Move();}
    /**
     * @brief Update: First this calls SetColor to perform the logic of changing the busses color. Then it calls the Update method of the base bus.
     * 
     */
    void Update() {
        Color white{255,255,255,255};
        this->SetColor(white);
        wrapped_bus_->Update();
    }
    void Report(std::ostream& ostr) {wrapped_bus_->Report(ostr);}
    void UpdateBusData() {wrapped_bus_->UpdateBusData();}
    BusData GetBusData() const {return wrapped_bus_->GetBusData();}
    std::string GetName() const {return wrapped_bus_->GetName();}
    Stop * GetNextStop() const {return wrapped_bus_->GetNextStop();}
    size_t GetNumPassengers() const {return wrapped_bus_->GetNumPassengers();}
    int GetCapacity() const {return wrapped_bus_->GetCapacity();}

 private:
};

#endif  // SRC_BUS_COLOR_DECORATOR_H_
