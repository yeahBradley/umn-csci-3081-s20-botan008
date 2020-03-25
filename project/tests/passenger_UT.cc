/*
 * Students: Use this file as a guide to writing your own unit tests.
 * See the project instructions for more information on which classes
 * and methods must be tested.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

/*******************************************************************************
* TEST FEATURE SetUp
*******************************************************************************/
class PassengerTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *passenger, *passenger1, *passenger2;

  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete passenger;
    passenger = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
  }
};

/*******************************************************************************
 * Test Cases: All public methods
 ******************************************************************************/
TEST_F(PassengerTests, Constructor_default) { //get destination is the only getter
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetDestination(), -1);

  testing::internal::CaptureStdout();
  passenger->Report(cout);
  string output1 = testing::internal::GetCapturedStdout();

  string expected_output1_name_ = "Name: Nobody";
  string expected_output1_destination_stop_id_ = "Destination: -1";
  EXPECT_GE(output1.find(expected_output1_name_), 0);
  EXPECT_GE(output1.find(expected_output1_destination_stop_id_), 0);
}
TEST_F(PassengerTests, Constructor_params) { //get destination is the only getter
  passenger = new Passenger(1, "Bradley");
  EXPECT_EQ(passenger->GetDestination(), 1);

  testing::internal::CaptureStdout();
  passenger->Report(cout);
  string output1 = testing::internal::GetCapturedStdout();

  string expected_output1_name_ = "Name: Bradley";
  string expected_output1_destination_stop_id_ = "Destination: 1";
  EXPECT_GE(output1.find(expected_output1_name_), 0);
  EXPECT_GE(output1.find(expected_output1_destination_stop_id_), 0);
}
TEST_F(PassengerTests, Update_OnBus) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetTotalWait(), 0);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
  EXPECT_EQ(passenger->GetTotalWait(), 1);
  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 2);
  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 3);
}
TEST_F(PassengerTests, Update_OffBus) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetTotalWait(), 0);
  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 1);
  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 2);
}
TEST_F(PassengerTests, GetOnBus) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
}
TEST_F(PassengerTests, GetTotalWait) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetTotalWait(), 0);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(), 1);
}
TEST_F(PassengerTests, IsOnBus) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
}
TEST_F(PassengerTests, GetDestination) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetDestination(), -1);
  passenger1 = new Passenger(1, "Bradley");
  EXPECT_EQ(passenger1->GetDestination(), 1);

  EXPECT_NE(passenger->GetDestination(), passenger1->GetDestination());
}
TEST_F(PassengerTests, Report) {
  passenger = new Passenger(1, "Bradley");

  testing::internal::CaptureStdout();
  passenger->Report(cout);
  string output1 = testing::internal::GetCapturedStdout();

  string expected_output1_name_ = "Name: Bradley";
  string expected_output1_destination_stop_id_ = "Destination: 1";
  string expected_output1_totalWait = "Total Wait: 0";
  string expected_output1_wait_at_stop_ = "\tWait at Stop: 0";
  string expected_output1_time_on_bus_ = "\tTime on bus: 0";

  EXPECT_GE(output1.find(expected_output1_name_), 0);
  EXPECT_GE(output1.find(expected_output1_destination_stop_id_), 0);
  EXPECT_GE(output1.find(expected_output1_totalWait), 0);
  EXPECT_GE(output1.find(expected_output1_wait_at_stop_), 0);
  EXPECT_GE(output1.find(expected_output1_time_on_bus_), 0);
}
