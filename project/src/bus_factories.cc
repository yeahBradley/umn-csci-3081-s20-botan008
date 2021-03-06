/**
 * @file bus_factories.cc
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */
#include "src/bus_factories.h"
#include <time.h>
#include <iostream>
#include <vector>
#include <random>

enum TheTime {
  TT_MORNING = 1, TT_AFTERNOON = 2, TT_EVENING = 3, TT_OVERNIGHT = 4
};

Bus* StrategyBusFactory::GenerateBus(std::string name, Route* out, Route* in,
double speed) {
    std::cout << "*********************" << std::endl;
    std::cout << "Strategy Bus Factory" << std:: endl;

    int theTime;
    int busType;
    SmallBusFactory smallBusFactory;
    RegularBusFactory regularBusFactory;
    LargeBusFactory largeBusFactory;
    MorningStrategy morningStrategy;
    AfternoonStrategy afternoonStrategy;
    EveningStrategy eveningStrategy;
    OvernightStrategy overnightStrategy;

    struct tm timeinfo;
    time_t rawtime;
    char buf[50];

    rawtime = time(&rawtime);
    localtime_r(&rawtime, &timeinfo);

    std::cout << "Date/Time:   " << asctime_r(&timeinfo, buf);
    if (timeinfo.tm_hour >= 6 && timeinfo.tm_hour < 8) {
      theTime = TT_MORNING;
    } else if (timeinfo.tm_hour >= 8 && timeinfo.tm_hour < 15) {
      theTime = TT_AFTERNOON;
    } else if (timeinfo.tm_hour >= 15 && timeinfo.tm_hour < 20) {
      theTime = TT_EVENING;
    } else {
      theTime = TT_OVERNIGHT;
    }

    // std::cout << "   theTime:_" << theTime << std::endl;
    switch (theTime) {
        case 1:
            std::cout << "Morning Strategy (1) was used" << std::endl;
            busType = morningStrategy.execute();
            break;
        case 2:
            std::cout << "Afternoon Strategy (2) was used" << std::endl;
            busType = afternoonStrategy.execute();
            break;
        case 3:
            std::cout << "Evening Strategy (3) was used" << std::endl;
            busType = eveningStrategy.execute();
            break;
        case 4:
            std::cout << "Overnight Strategy (small) was used" << std::endl;
            busType = overnightStrategy.execute();
            break;
        default:
            std::cout << "ERROR: DEFAULT CASE!!!!!!!!/n" << std::endl;
            busType = BT_REGULAR;
    }
    // std::cout << "   busType:_" << busType << std::endl;
    switch (busType) {
        case 30:
            std::cout << "Small bus was generated" << std::endl;
            return smallBusFactory.GenerateBus(name, out, in, speed);
        case 60:
            std::cout << "Regular bus was generated" << std::endl;
            return regularBusFactory.GenerateBus(name, out, in, speed);
        case 90:
            std::cout << "Regular bus was generated" << std::endl;
            return largeBusFactory.GenerateBus(name, out, in, speed);
        default:
            std::cout << "ERROR: DEFAULT CASE!!!!!!!!/n" << std::endl;
            return regularBusFactory.GenerateBus(name, out, in, speed);
    }
}

Bus* RandomBusFactory::GenerateBus(std::string name, Route* out, Route* in,
double speed) {
    SmallBusFactory smallBusFactory;
    RegularBusFactory regularBusFactory;
    LargeBusFactory largeBusFactory;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);
    int rand_int = dist1(rng);

    switch (rand_int) {
        case 1:
            return smallBusFactory.GenerateBus(name, out, in, speed);
        case 2:
            return regularBusFactory.GenerateBus(name, out, in, speed);
        case 3:
            return largeBusFactory.GenerateBus(name, out, in, speed);
        default:
            return regularBusFactory.GenerateBus(name, out, in, speed);
    }
}

SmallBus* SmallBusFactory::GenerateBus(std::string name, Route* out, Route* in,
double speed) {
    SmallBus *bus1;
    bus1 = new SmallBus(name, out, in, speed);
    return bus1;
}

RegularBus* RegularBusFactory::GenerateBus(std::string name, Route* out,
Route* in, double speed) {
    RegularBus *bus1;
    bus1 = new RegularBus(name, out, in, speed);
    return bus1;
}

LargeBus* LargeBusFactory::GenerateBus(std::string name, Route* out, Route* in,
double speed) {
    LargeBus *bus1;
    bus1 = new LargeBus(name, out, in, speed);
    return bus1;
}
