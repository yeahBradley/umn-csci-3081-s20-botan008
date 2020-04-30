// Copyright 2020 Bradley Botanel
#ifndef WEB_VISUALIZATION_SIMULATOR_H_
#define WEB_VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>
#include <string>

#include "web_code/web/web_interface.h"
#include "src/config_manager.h"
#include "src/file_writer.h"

class Route;
class Bus;
class Stop;

class VisualizationSimulator {
 public:
        VisualizationSimulator(WebInterface*, ConfigManager*);
        ~VisualizationSimulator();
        /**
         * @brief This method works in tandem with the back end observer pattern to clear registered busses
         *
         */
        void ClearListeners();
        /**
         * @brief This method works in tandem with the back end observer pattern to register the selected bus
         *
         * @param[in] string* id: pointer to the name of the bus that will registered
         * @param[in] IObserver* observer: pointer to the observer that will be registered with the subject
         *
         */
        void AddListener(std::string* id, IObserver* observer);
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
        std::vector<Bus *> busses_;

        int busId = 1000;
        bool isPaused = false;
        std::string bus_stats_file_name_ = "BusData.csv";
};

#endif  // WEB_VISUALIZATION_SIMULATOR_H_
