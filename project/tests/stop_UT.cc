

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>

#include "../src/stop.h"
#include "../src/bus.h"
#include "../src/passenger.h"
#include "../src/random_passenger_generator.h"

using namespace std;
/*******************************************************************************
 * TEST FEATURE SetUp
 ******************************************************************************/
class StopTests : public ::testing::Test {
protected:
  Stop *stop, *stop1;

  // virtual void SetUp() {
  //
  // }

  virtual void TearDown() {
    delete stop;
    stop = NULL;
  }
};

/*******************************************************************************
 * Test Cases: Constructors and methods that return a boolean
 ******************************************************************************/
TEST_F(StopTests, Constructor_params) {  // int id, double longitude, double latitude
  stop = new Stop(1, 50.0, 50.0);
  EXPECT_EQ(stop->GetId(), 1);
  EXPECT_EQ(stop->GetLongitude(), 50.0);
  EXPECT_EQ(stop->GetLatitude(), 50.0);

  stop1 = new Stop(-1, -50.0, -50.0);
  EXPECT_EQ(stop1->GetId(), -1);
  EXPECT_EQ(stop1->GetLongitude(), -50.0);
  EXPECT_EQ(stop1->GetLatitude(), -50.0);
  delete stop1;
}
TEST_F(StopTests, Constructor_default) {
  stop = new Stop(1);
  EXPECT_EQ(stop->GetId(), 1);
  EXPECT_EQ(stop->GetLongitude(), 44.973723);
  EXPECT_EQ(stop->GetLatitude(), -93.235365);

  stop1 = new Stop(-1);
  EXPECT_EQ(stop1->GetId(), -1);
  EXPECT_EQ(stop1->GetLongitude(), 44.973723);
  EXPECT_EQ(stop1->GetLatitude(), -93.235365);
  delete stop1;
}
TEST_F(StopTests, LoadPassengers) {
  cout << "TODO: EC" << endl;
}
TEST_F(StopTests, AddPassengers) {
  cout << "TODO: EC" << endl;
}
TEST_F(StopTests, Update) {
  cout << "TODO: EC" << endl;
}
TEST_F(StopTests, GetId) {
  cout << "TODO: EC" << endl;
}
TEST_F(StopTests, Report) {
  cout << "TODO: EC" << endl;
}
// int LoadPassengers(Bus *);
// int AddPassengers(Passenger *);
// void Update();
// int GetId() const;
// void Report(std::ostream&) const;
// double = 44.973723, double = -93.235365
// double GetLongitude() const { return longitude_; }
// double GetLatitude() const { return latitude_; }
