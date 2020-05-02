

#include "src/bus_color_decorator.h"

void BusColorDecorator::SetColor() {
    BusData currentBusData = wrapped_bus_->GetBusData();
    if (wrapped_bus_->IsOutgoingRouteComplete()) {
        currentBusData.color.red = 212;
        currentBusData.color.green = 175;
        currentBusData.color.blue = 55;
        wrapped_bus_->SetBusData(currentBusData);
    } else {
        currentBusData.color.red = 178;
        currentBusData.color.green = 34;
        currentBusData.color.blue = 34;
        wrapped_bus_->SetBusData(currentBusData);
    } 
}

void BusColorDecorator::Update() {
    this->SetColor();
    wrapped_bus_->Update();
}