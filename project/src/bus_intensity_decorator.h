/**
 * @file bus_intensity_decorator.h
 * 
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_BUS_INTENSITY_DECORATOR_H_
#define SRC_BUS_INTENSITY_DECORATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/i_bus_decorator.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief BusIntensityDecorator: A concrete class of the bus decorator interface. All the methods save Setintensity and Update are simple pass-through methods to the base class object.
 */
class BusIntensityDecorator : public IBusDecorator {
 protected:
    IBus *wrapped_bus_;

 public:
    /**
     * @brief BusIntensityDecorator : The constructor for this decorator class only needs to store the base class object it was given.
     * 
     * @param[in] Bus* baseBus : pointer to the base bus object that will be decorated by this class
     */
    explicit BusIntensityDecorator(IBus* baseBus) : wrapped_bus_(baseBus) {}
    bool IsTripComplete() {return wrapped_bus_->IsTripComplete();}
    bool LoadPassenger(Passenger* pass) {
        return wrapped_bus_->LoadPassenger(pass);}
    bool IsOutgoingRouteComplete() {
        return wrapped_bus_->IsOutgoingRouteComplete();}
    /**
     * @brief SetIntensity: The decorator uses this method to change the alpha Intensity of its base bus
     */
    void SetIntensity() {
        BusData BusData = wrapped_bus_->GetBusData();
        int alpha;
        // To make the changes in alpha more noticable the alpha channel starts
        // at 160 and increases by 15 for each passenger up to 6 passengers.
        // With 7 or more passengers the alpha is locked at 255.
        switch (BusData.capacity) {
            case 30:
                if (BusData.num_passengers < 7) {
                    alpha = 160 + (15 * BusData.num_passengers);
                } else {
                    alpha = 255;
                }
                break;
            case 60:
                if (BusData.num_passengers < 7) {
                    alpha = 160 + (15 * BusData.num_passengers);
                } else {
                    alpha = 255;
                }
                break;
            case 90:
                if (BusData.num_passengers < 7) {
                    alpha = 160 + (15 * BusData.num_passengers);
                } else {
                    alpha = 255;
                }
                break;
            default:
                alpha = 255;
        }
        // std::cout << "         " << alpha << std::endl;
        BusData.color.alpha = alpha;
        wrapped_bus_->SetBusData(BusData);
    }
    void SetBusData(BusData BusData) {
        wrapped_bus_->SetBusData(BusData);
    }
    bool Move() {return wrapped_bus_->Move();}
    /**
     * @brief Update: First this calls SetIntensity to perform the logic of changing the busses alpha Intensity. Then it calls the Update method of the base bus.
     * 
     */
    void Update() {
        this->SetIntensity();
        wrapped_bus_->Update();
    }
    void Report(std::ostream& ostr) {wrapped_bus_->Report(ostr);}
    void UpdateBusData() {wrapped_bus_->UpdateBusData();}
    BusData GetBusData() const {return wrapped_bus_->GetBusData();}
    std::string GetName() const {return wrapped_bus_->GetName();}
    Stop * GetNextStop() const {return wrapped_bus_->GetNextStop();}
    size_t GetNumPassengers() const {return wrapped_bus_->GetNumPassengers();}
    int GetCapacity() const {return wrapped_bus_->GetCapacity();}
    void RegisterObserver(IObserver<BusData*> * observer) {
        wrapped_bus_->RegisterObserver(observer);}
    void ClearObservers() {wrapped_bus_->ClearObservers();}

 private:
};

#endif  // SRC_BUS_INTENSITY_DECORATOR_H_
