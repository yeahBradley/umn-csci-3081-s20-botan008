

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>

#include "../src/route.h"
#include "../src/stop.h"
#include "../src/bus.h"
#include "../src/passenger.h"
#include "../src/random_passenger_generator.h"

using namespace std;

/*******************************************************************************
 * TEST FEATURE SetUp
 ******************************************************************************/
class RouteTests : public ::testing::Test {
protected:
  Route *route;
  Stop ** stops;
  list<Stop *> stops_list;
  Stop * stop1;
  Stop * stop2;
  Stop * stop3;

  double *distances;
  int num_stops = 3;

  string name = "one";

  virtual void SetUp() {
    //Stop ** stops;
    stops = new Stop *[4];
    //list<Stop *> stops_list;
    //Stop * stop1
    stop1 = new Stop(0, 25.0, 25.0);
    //Stop * stop2
    stop2 = new Stop(1, 50.0, 50.0);
    //Stop * stop3
    stop3 = new Stop(2, 75.0, 75.0);
    stops_list.push_back(stop1);
    stops[0] = stop1;
    stops_list.push_back(stop2);
    stops[1] = stop2;
    stops_list.push_back(stop3);
    stops[2] = stop3;

    //double *distances;
    distances = new double[3];
    distances[0] = 5;
    distances[1] = 4;
    distances[2] = 3;

    std::list<double> probs;
    probs.push_back(.5);
    probs.push_back(.5);
    probs.push_back(0);
    RandomPassengerGenerator PassengerGenerator = RandomPassengerGenerator(probs, stops_list);

    route = new Route(name, stops, distances, num_stops, &PassengerGenerator);
  }

  virtual void TearDown() {
    delete[] distances;
    // cout << "delete[] distances completed" << endl;
    for (int i = 0; i < 3; i++) {
      delete stops[i];
      // cout << "delete stops[" << i << "] completed" << endl;
    }
    delete stops;
    // cout << "delete stops completed" << endl;
    delete route;
    // cout << "delete route completed" << endl;
    route = NULL;
  }
};

/*******************************************************************************
 * Test Cases: Constructors and methods that return a boolean
 ******************************************************************************/
TEST_F(RouteTests, Constructor_default) {  // name, **stops, *distances, num_stops, *PassengerGenerator

  // Testing GetName Getter function
  EXPECT_EQ(route->GetName(), name);

  // Testing GetStops getter function
  list<Stop *> output = route->GetStops();
  list<Stop *> tmp = stops_list;
  for(int i = 0; i < 3; i++) {
    // cout << "list: " << i << endl;
    EXPECT_EQ(tmp.front(), output.front());
    tmp.pop_front();
    output.pop_front();
  }
  // cout << "size of stops_list is " << stops_list.size() << endl;

  // Testing GetDestinationStop getter function
  Stop *output1 = route->GetDestinationStop();
  EXPECT_EQ(stops[0], output1);

  // Testing GetRouteData getter function experimental
  route->UpdateRouteData();
  RouteData output2 = route->GetRouteData();
  EXPECT_EQ(output2.id, "one");
}
TEST_F(RouteTests, IsAtEnd_false) {
  string name = "one";

  Stop ** stops = new Stop *[4];
  list<Stop *> stops_list;
  Stop * stop1 = new Stop(0, 25.0, 25.0);
  Stop * stop2 = new Stop(1, 50.0, 50.0);
  Stop * stop3 = new Stop(2, 75.0, 75.0);
  stops_list.push_back(stop1);
  stops[0] = stop1;
  stops_list.push_back(stop2);
  stops[1] = stop2;
  stops_list.push_back(stop3);
  stops[2] = stop3;

  double *distances = new double[3];
  distances[0] = 5;
  distances[1] = 4;
  distances[2] = 3;

  int num_stops = 3;

  std::list<double> probs;
  probs.push_back(.5);
  probs.push_back(.5);
  probs.push_back(0);
  RandomPassengerGenerator PassengerGenerator = RandomPassengerGenerator(probs, stops_list);

  route = new Route(name, stops, distances, num_stops, &PassengerGenerator);

  EXPECT_NE(route->IsAtEnd(), true);
  EXPECT_EQ(route->IsAtEnd(), false);

  delete[] distances;
  // cout << "delete[] distances completed" << endl;
  for (int i = 0; i < 3; i++) {
    delete stops[i];
    // cout << "delete stops[" << i << "] completed" << endl;
  }
  delete stops;
  // cout << "delete stops completed" << endl;
}
TEST_F(RouteTests, IsAtEnd_true) {
  string name = "one";

  Stop ** stops = new Stop *[4];
  list<Stop *> stops_list;
  Stop * stop1 = new Stop(0, 25.0, 25.0);
  Stop * stop2 = new Stop(1, 50.0, 50.0);
  Stop * stop3 = new Stop(2, 75.0, 75.0);
  stops_list.push_back(stop1);
  stops[0] = stop1;
  stops_list.push_back(stop2);
  stops[1] = stop2;
  stops_list.push_back(stop3);
  stops[2] = stop3;

  double *distances = new double[3];
  distances[0] = 5;
  distances[1] = 4;
  distances[2] = 3;

  int num_stops = 3;

  std::list<double> probs;
  probs.push_back(.5);
  probs.push_back(.5);
  probs.push_back(0);
  RandomPassengerGenerator PassengerGenerator = RandomPassengerGenerator(probs, stops_list);

  route = new Route(name, stops, distances, num_stops, &PassengerGenerator);

  route->ToNextStop();  // increment destination_stop_index_
  route->ToNextStop();  // increment destination_stop_index_
  route->ToNextStop();  // increment destination_stop_index_

  // Now, destination_stop_index_ = 3 >= num_stops_
  EXPECT_EQ(route->IsAtEnd(), true);
  EXPECT_NE(route->IsAtEnd(), false);

  delete[] distances;
  // cout << "delete[] distances completed" << endl;
  for (int i = 0; i < 3; i++) {
    delete stops[i];
    // cout << "delete stops[" << i << "] completed" << endl;
  }
  delete stops;
  // cout << "delete stops completed" << endl;
}

// TEST_F(RouteTests, Clone) {
//   cout << "TODO: EC" << endl;
// }
// TEST_F(RouteTests, Update) {
//   cout << "TODO: EC" << endl;
// }
// TEST_F(RouteTests, Report) {
//   cout << "TODO: EC" << endl;
// }
// TEST_F(RouteTests, PrevStop) {
//   cout << "TODO: EC" << endl;
// }
// TEST_F(RouteTests, NextStop) {
//   cout << "TODO: EC" << endl;
// }
// TEST_F(RouteTests, GetDestinationStop) {
//   cout << "TODO: EC" << endl;
// }
// TEST_F(RouteTests, GetTotalRouteDistance) {
//   cout << "TODO: EC" << endl;
// }
// TEST_F(RouteTests, GetNextStopDistance) {
//   cout << "TODO: EC" << endl;
// }
// TEST_F(RouteTests, UpdateRouteData) {
//   cout << "TODO: EC" << endl;
// }
// TEST_F(RouteTests, GetRouteData) {
//   cout << "TODO: EC" << endl;
// }
