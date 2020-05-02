// Copyright 2020 Bradley Botanel
#ifndef WEB_VISUALIZATION_SIMULATOR_H_
#define WEB_VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>
#include <string>

#include "web_code/web/web_interface.h"
#include "src/config_manager.h"
#include "src/file_writer.h"
#include "src/bus_factories.h"
#include "src/i_bus.h"
#include "src/i_bus_decorator.h"
#include "src/bus_color_decorator.h"
#include "src/bus_intensity_decorator.h"

class Route;
class Bus;
class Stop;

class VisualizationSimulator {
 public:
        VisualizationSimulator(WebInterface*, ConfigManager*);
        ~VisualizationSimulator();
        /**
         * @brief ClearBusListeners: This method works in tandem with the back end observer pattern to clear registered busses
         *
         */
        void ClearBusListeners();
        /**
         * @brief AddBusListener: This method works in tandem with the back end observer pattern to register the selected bus
         *
         * @param[in] string* id: pointer to the name of the bus that will registered
         * @param[in] IObserver<BusData*>* observer: pointer to the observer that will be registered with the subject. Note that IObserver is a template class
         *
         */
        void AddBusListener(std::string* id, IObserver<BusData*>* observer);
        /**
         * @brief ClearStopListeners: This method works in tandem with the back end observer pattern to clear registered stops
         *
         */
        void ClearStopListeners();
        /**
         * @brief This method works in tandem with the back end observer pattern to register the selected stop
         *
         * @param[in] string* id: pointer to the name of the bus that will registered
         * @param[in] IObserver<StopData*>* observer: pointer to the observer that will be registered with the subject. Note that IObserver is a template class
         *
         */
        void AddStopListener(std::string* id, IObserver<StopData*>* observer);
        /**
         * @brief A functioning pause button was added to the browser display
         *
         */
        void Pause();
        void Start(const std::vector<int>&, const int&);
        /**
         * @brief Update tics every element of the simulation forward in time
         */
        void Update();

 private:
        WebInterface* webInterface_;
        ConfigManager* configManager_;

        std::vector<int> busStartTimings_;
        std::vector<int> timeSinceLastBus_;
        int numTimeSteps_;
        int simulationTimeElapsed_;

        std::vector<Route *> prototypeRoutes_;
        std::vector<IBus *> busses_;

        int busId = 1000;
        bool isPaused = false;
        std::string bus_stats_file_name_ = "BusData.csv";
};

#endif  // WEB_VISUALIZATION_SIMULATOR_H_
