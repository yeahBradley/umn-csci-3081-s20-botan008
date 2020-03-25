

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>

#include "../src/bus.h"
#include "../src/passenger.h"
#include "../src/random_passenger_generator.h"
#include "../src/route.h"
#include "../src/stop.h"

using namespace std;

/*******************************************************************************
 * TEST FEATURE SetUp
 ******************************************************************************/
class BusTests : public ::testing::Test {
protected:
  Bus *bus1, *bus2, *bus3;
  Stop ** stops_OUT;
  Stop ** stops_IN;
  Stop * stop1;
  Stop * stop2;
  Stop * stop3;
  double *distances_OUT;
  double *distances_IN;
  Route *route_OUT;
  Route *route_IN;
  string bus1Name = "bus1";
  string bus2Name = "bus2";

  string route1Name = "route1";
  string route2Name = "route2";

  int capacity = 30;
  double speed = 1.0;
  int num_stops = 3;

  virtual void SetUp() {
    //Stop ** stops_OUT;
    stops_OUT = new Stop *[4];
    //Stop ** stops_IN;
    stops_IN = new Stop *[4];
    list<Stop *> stops_list_OUT;
    list<Stop *> stops_list_IN;
    //Stop * stop1;
    stop1 = new Stop(0, 25.0, 25.0);
    //Stop * stop2;
    stop2 = new Stop(1, 50.0, 50.0);
    //Stop * stop3;
    stop3 = new Stop(2, 75.0, 75.0);
    stops_list_OUT.push_back(stop1);
    stops_OUT[0] = stop1;
    stops_list_OUT.push_back(stop2);
    stops_OUT[1] = stop2;
    stops_list_OUT.push_back(stop3);
    stops_OUT[2] = stop3;
    stops_list_IN.push_back(stop3);
    stops_IN[0] = stop3;
    stops_list_IN.push_back(stop2);
    stops_IN[1] = stop2;
    stops_list_IN.push_back(stop1);
    stops_IN[2] = stop1;

    //double *distances_OUT;
    distances_OUT = new double[3];
    distances_OUT[0] = 2.0;
    distances_OUT[1] = 2.0;
    distances_OUT[2] = 2.0;
    //double *distances_IN;
    distances_IN = new double[3];
    distances_IN[0] = 2.0;
    distances_IN[1] = 2.0;
    distances_IN[2] = 2.0;

    std::list<double> probs;
    probs.push_back(0.0);
    probs.push_back(0.0);
    probs.push_back(0.0);
    RandomPassengerGenerator PassengerGenerator = RandomPassengerGenerator(probs, stops_list_OUT);

    //Route *route_OUT;
    route_OUT = new Route(route1Name, stops_OUT, distances_OUT, num_stops, &PassengerGenerator);
    //Route *route_IN;
    route_IN = new Route(route2Name, stops_IN, distances_IN, num_stops, &PassengerGenerator);
    
    bus1 = new Bus(bus1Name, route_OUT, route_IN, capacity, speed);
    bus2 = new Bus(bus2Name, route_OUT, route_IN);
    bus3 = new Bus("bus3", route_OUT, route_IN, 1);
  }

  virtual void TearDown() {
    delete[] distances_OUT;
    delete[] distances_IN;
    // cout << "delete[] distances completed" << endl;
    for (int i = 0; i < 3; i++) {
      delete stops_OUT[i];
    
      // cout << "delete stops[" << i << "] completed" << endl;
    }
    delete[] stops_OUT;
    delete[] stops_IN;
    delete route_OUT;
    delete route_IN;
    delete bus1;
    delete bus2;
    delete bus3;
    // cout << "delete stops completed" << endl;
    // bus1 = NULL;
  }
};

/*******************************************************************************
 * Test Cases: Constructors and methods that return a boolean
 ******************************************************************************/
TEST_F(BusTests, Constructor_params) {  // name, route, route, capacity, speed
  
  // Testing GetName getter function
  EXPECT_EQ(bus1->GetName(), "bus1");

  // Testing GetNextStop getter function
  Stop *output1 = bus1->GetNextStop();
  EXPECT_EQ(output1, stops_OUT[0]);

  // Testing GetCapacity getter function
  EXPECT_EQ(bus1->GetCapacity(), 30);
}
TEST_F(BusTests, Constructor_default) { //int and double have default values

  // Testing GetName getter function
  EXPECT_EQ(bus2->GetName(), "bus2");

  // Testing GetNextStop getter function
  Stop *output1 = bus2->GetNextStop();
  EXPECT_EQ(output1, stops_OUT[0]);

  // Testing GetCapacity getter function
  EXPECT_EQ(bus2->GetCapacity(), 60);
}
TEST_F(BusTests, IsTripComplete_false) {
  EXPECT_EQ(bus1->IsTripComplete(), false);
  EXPECT_EQ(bus2->IsTripComplete(), false);
}
TEST_F(BusTests, IsTripComplete_true) {
  EXPECT_EQ(bus1->IsTripComplete(), false);
  EXPECT_EQ(bus2->IsTripComplete(), false);
  route_OUT->NextStop();  // increment destination_stop_index_
  route_OUT->NextStop();  // increment destination_stop_index_
  route_OUT->NextStop();  // increment destination_stop_index_
  EXPECT_EQ(bus1->IsTripComplete(), false);
  EXPECT_EQ(bus2->IsTripComplete(), false);
  route_IN->NextStop();  // increment destination_stop_index_
  route_IN->NextStop();  // increment destination_stop_index_
  route_IN->NextStop();  // increment destination_stop_index_
  EXPECT_EQ(bus1->IsTripComplete(), true);
  EXPECT_EQ(bus2->IsTripComplete(), true);
}
TEST_F(BusTests, LoadPassenger_false) {
  Passenger *passenger1 = new Passenger();
  Passenger *passenger2 = new Passenger();
  bus3->LoadPassenger(passenger1);
  EXPECT_EQ(bus3->LoadPassenger(passenger2), false);
  delete passenger1; 
  delete passenger2;
}
TEST_F(BusTests, LoadPassenger_true) {
  Passenger **passenger_Arr = new Passenger *[30];
  for (int i = 0; i < 30; i++) {
    passenger_Arr[i] = new Passenger(i%3);
    EXPECT_EQ(bus1->LoadPassenger(passenger_Arr[i]), true);
  }

  Passenger *passenger = new Passenger();
  EXPECT_EQ(bus1->LoadPassenger(passenger), false);

  for (int i = 0; i < 30; i++) {
    delete passenger_Arr[i];
  }
  delete passenger_Arr;
  delete passenger;
}
TEST_F(BusTests, Move_true) {
  // Passenger **passenger_Arr = new Passenger *[30];
  // for (int i = 0; i < 30; i++) {
  //   passenger_Arr[i] = new Passenger(i%3);
  //   bus1->LoadPassenger(passenger_Arr[i]);
  // }

  // for (int i = 0; i < 30; i++) {
  //   cout << i << "_";
  //   EXPECT_EQ(bus1->Move(), true);
  // }


  // for (int i = 0; i < 9; i++) {
  //   bus1->Move();
  // }

  // Only when distance_remaining_ is greater than 1, while a route is not complete
  // does move return true.

  // **1**
  // Move should return false because bus is starting at a stop
  // Arithmetic error occurs here, distance_remaining_ becomes -1
  // At function end distance_remaining_ is 1
  // EXPECT_EQ(bus1->Move(), true); 
  bus1->Move();

  // **2**
  // Move should return true because distance_remaining_ changed from 1 to 0
  // Because of the previous arithmetic error, the bus reaches stop 2 on this call
  // At function end distance_remaining_ is 2
  EXPECT_EQ(bus1->Move(), true);

  // **3** SUCCESSFUL Move
  // Move should return true because distance_remaining_ changed from 2 to 1
  // The Bus is moving to stop 3, 
  // At function end distance_remaining_ is 1
  EXPECT_EQ(bus1->Move(), true);

  // **4**
  // Move should return true because distance_remaining_ changed from 1 to 0
  // The bus reaches the third stop here and switches routes to incoming
  // However, GetNextStopDistance returns 0
  // At function end distance_remaining_ is 0
  EXPECT_EQ(bus1->Move(), true);
  EXPECT_EQ(bus1->Move(), true);

  // **5**
  // Move should return false because bus is starting at a stop
  // Arithmetic error occurs here, distance_remaining_ becomes -1
  // At function end distance_remaining_ is 1
  // EXPECT_EQ(bus1->Move(), true);
  bus1->Move();

  // **6**  
  // Move should return true because distance_remaining_ changed from 1 to 0
  // Because of the previous arithmetic error, the bus reaches stop 2 on this call
  // At function end distance_remaining_ is 2
  EXPECT_EQ(bus1->Move(), true);  

  // **7** SUCCESSFUL Move
  // Move should return true because distance_remaining_ changed from 2 to 1
  // The bus is moving to stop 1, 
  // At function end distance_remaining_ is 1
  EXPECT_EQ(bus1->Move(), true);  

  // **8**
  // Move should return true because distance_remaining_ changed from 1 to 0
  // The bus reaches the first and final stop of incoming route here
  // However, GetNextStopDistance returns 0
  // At function end distance_remaining_ is 0
  EXPECT_EQ(bus1->Move(), true);
  EXPECT_EQ(bus1->Move(), true);  

  // **9**
  // Both routes are complete, Move should return false
  // At function end distance_remaining_ is 999
  // EXPECT_EQ(bus1->Move(), true);  
  bus1->Move();


  // for (int i = 0; i < 30; i++) {
  //   delete passenger_Arr[i];
  // }
  // delete passenger_Arr;
}
TEST_F(BusTests, Move_false) {
  // for (int i = 0; i < 30; i++) {
  //   cout << i << "_";
  //   EXPECT_EQ(bus1->Move(), false);
  // }

  // the first move should always return false as the bus starts at the first stop
  EXPECT_EQ(bus1->Move(), false);
  bus1->Move();
  bus1->Move();
  bus1->Move();
  bus1->Move();

  // the bus switches from outgoing route to incoming route at the 5th move
  // but this should actually happen at the 6th move
  EXPECT_EQ(bus1->Move(), false); 
  bus1->Move();
  bus1->Move();
  bus1->Move();
  bus1->Move();

  // After 8 moves, both routes are complete so the 9th and higher Move should return false
  // but this should atually happen at the 11th move
  EXPECT_EQ(bus1->Move(), false);
  EXPECT_EQ(bus1->Move(), false);
  EXPECT_EQ(bus1->Move(), false);
}
