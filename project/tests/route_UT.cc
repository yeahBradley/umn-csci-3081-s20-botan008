

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

  // virtual void SetUp() {
  //
  // }

  virtual void TearDown() {
    //delete route;
    //route = NULL;
  }
};

/*******************************************************************************
 * Test Cases: Constructors and methods that return a boolean
 ******************************************************************************/
TEST_F(RouteTests, Constructor_default) {  // name, **stops, *distances, num_stops, *PassengerGenerator
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


  cout << "TODO: in progress" << endl;

  // delete[] distances;
  // for (int i = 0; i < 3; i++) {
  //   delete stops[i];
  // }
  // delete[] stops;
}
TEST_F(RouteTests, IsAtEnd) {
  cout << "TODO" << endl;
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


// Route(std::string name, Stop ** stops, double * distances, int num_stops,
//       PassengerGenerator *);
// Route * Clone();
// void Update();
// void Report(std::ostream&);
// bool IsAtEnd() const;
//
// Stop *  PrevStop();  // Returns stop before destination stop
// void NextStop();  // Change destination_stop_ to next stop
// Stop * GetDestinationStop() const;    // Get pointer to next stop
// double GetTotalRouteDistance() const;
// double GetNextStopDistance() const;
//
// // Vis Getters
// std::string GetName() const { return name_; }
// std::list<Stop *> GetStops() const { return stops_; }
// void UpdateRouteData();
// RouteData GetRouteData() const;
