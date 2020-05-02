

#include "src/bus_intensity_decorator.h"

void BusIntensityDecorator::SetIntensity() {
    BusData BusData = wrapped_bus_->GetBusData();
    int alpha;
    // large bus: 75 - 255; each passenger is worth 2 points of intensity
    // regular bus: 75 - 255; each passenger is worth 3
    // small bus: 75 - 255; each passenger is worth 6

    // std::cout << "*********" << std::endl;
    // std::cout << "*********" << std::endl;
    // std::cout << "*********" << std::endl;
    // std::cout << "         " << BusData.capacity << std::endl;
    // std::cout << "         " << BusData.num_passengers << std::endl;
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

void BusIntensityDecorator::Update() {
    this->SetIntensity();
    wrapped_bus_->Update();
}