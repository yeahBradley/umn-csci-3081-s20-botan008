// Copyright 2020 Bradley Botanel

#include <string>
#include "web_code/web/visualization_simulator.h"

VisualizationSimulator::VisualizationSimulator(WebInterface* webI,
  ConfigManager* configM) {
    webInterface_ = webI;
    configManager_ = configM;
}

VisualizationSimulator::~VisualizationSimulator() {}

void VisualizationSimulator::ClearBusListeners() {
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        busses_[i]->ClearObservers();
    }
}

void VisualizationSimulator::AddBusListener(std::string* id,
IObserver<BusData*>* observer) {
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        if (busses_[i]->GetName() == *id) {
            busses_[i]->RegisterObserver(observer);
        }
    }
}

void VisualizationSimulator::ClearStopListeners() {
    for (int i = static_cast<int>(prototypeRoutes_.size()) - 1; i >= 0; i--) {
        std::list<Stop *> stops_ = prototypeRoutes_[i]->GetStops();

        for (std::list<Stop *>::iterator it = stops_.begin();
        it != stops_.end(); it++) {
            (*it)->ClearObservers();
        }
    }
}

void VisualizationSimulator::AddStopListener(std::string* id,
IObserver<StopData*>* observer) {
    for (int i = static_cast<int>(prototypeRoutes_.size()) - 1;
    i >= 0; i--) {
        std::list<Stop *> stops_ = prototypeRoutes_[i]->GetStops();

        for (std::list<Stop *>::iterator it = stops_.begin();
        it != stops_.end(); it++) {
            if (std::to_string((*it)->GetId()) == *id) {
                (*it)->RegisterObserver(observer);
            }
        }
    }
}

void VisualizationSimulator::Pause() {
    if (isPaused == false) {
        isPaused = true;
        std::cout << "~~~~~~~~~~ The simulation is paused ~~~~~~~~~~" <<
        std::endl;
    } else {
        isPaused = false;
        std::cout << "~~~~~~~~~~ The simulation is running again ~~~~~~~~~~" <<
        std::endl;
    }
}

void VisualizationSimulator::Start(const std::vector<int>& busStartTimings,
  const int& numTimeSteps) {
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }

    simulationTimeElapsed_ = 0;

    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(std::cout);

        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }
}

void VisualizationSimulator::Update() {
    if (!isPaused) {
        simulationTimeElapsed_++;
        StrategyBusFactory strategyBusFactory;

        std::cout << "~~~~~~~~~~ The time is now " << simulationTimeElapsed_;
        std::cout << "~~~~~~~~~~" << std::endl;

        std::cout << "~~~~~~~~~~ Generating new busses if needed ";
        std::cout << "~~~~~~~~~~" << std::endl;

        // Check if we need to generate new busses
        for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
            // Check if we need to make a new bus
            if (0 >= timeSinceLastBus_[i]) {
                Route * outbound = prototypeRoutes_[2 * i];
                Route * inbound = prototypeRoutes_[2 * i + 1];

                Bus* newBus = strategyBusFactory.GenerateBus(
                  std::to_string(busId), outbound->Clone(),
                  inbound->Clone(), 1);

                BusColorDecorator* newColorBus =
                    new BusColorDecorator(newBus);
                BusIntensityDecorator* newIntensityBus =
                    new BusIntensityDecorator(newColorBus);

                busses_.push_back(newIntensityBus);

                busId++;

                timeSinceLastBus_[i] = busStartTimings_[i];
            } else {
                timeSinceLastBus_[i]--;
            }
        }

        std::cout << "~~~~~~~~~ Updating busses ";
        std::cout << "~~~~~~~~~" << std::endl;

        std::ostringstream log_output;
        std::ostringstream formatted_log;

        // Update busses
        for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
            busses_[i]->Update();

            if (busses_[i]->IsTripComplete()) {
                webInterface_->UpdateBus(busses_[i]->GetBusData(), true);
                busses_.erase(busses_.begin() + i);
                continue;
            }

            webInterface_->UpdateBus(busses_[i]->GetBusData());

            busses_[i]->Report(log_output);
            std::cout << log_output.str();
            FileWriter *temp = temp->GetInstance();
            formatted_log = temp->ProcessOutputStream(log_output);
            temp->WriteStream(bus_stats_file_name_, formatted_log);
        }

        std::cout << "~~~~~~~~~ Updating routes ";
        std::cout << "~~~~~~~~~" << std::endl;
        // Update routes
        for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
            prototypeRoutes_[i]->Update();

            webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());

            prototypeRoutes_[i]->Report(std::cout);
        }
    }
}
