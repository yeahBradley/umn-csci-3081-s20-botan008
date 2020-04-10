// Copyright 2020 Bradley Botanel
#ifndef WEB_VISUALIZATION_SIMULATOR_H_
#define WEB_VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>
#include <string>

#include "web_code/web/web_interface.h"
#include "src/config_manager.h"

class Route;
class Bus;
class Stop;

class VisualizationSimulator {
 public:
        VisualizationSimulator(WebInterface*, ConfigManager*);
        ~VisualizationSimulator();
        /**
         * @brief Method for the Observer Pattern that clears observers
         *
         */
        void ClearListeners();
        /**
         * @brief Method for the Observer Patter that adds observers
         *
         */
        void AddListener(std::string* id, IObserver* observer);
        /**
         * @brief A functioning pause button was added to the browser display
         *
         */
        void Pause();
        void Start(const std::vector<int>&, const int&);
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
};

#endif  // WEB_VISUALIZATION_SIMULATOR_H_
