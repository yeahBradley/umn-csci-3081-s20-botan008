

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
  Bus *bus;

  virtual void SetUp() {
    //bus = new Bus();  // 5 params, string, route*, route*, int, double
  }

  virtual void TearDown() {
    delete bus;
    bus = NULL;
  }
};

/*******************************************************************************
 * Test Cases: Constructors and methods that return a boolean
 ******************************************************************************/
TEST_F(BusTests, Constructor_params) {
  //bus = new Bus();
  cout << "TODO" << endl;
}

TEST_F(BusTests, Constructor_default) { //int and double have default values
  //bus = new Bus();
  cout << "TODO" << endl;
}

TEST_F(BusTests, IsTripComplete) {
  //bus = new Bus();
  cout << "TODO" << endl;
}
TEST_F(BusTests, LoadPassenger) {
  //bus = new Bus();
  cout << "TODO" << endl;
}
TEST_F(BusTests, Move) {
  //bus = new Bus();
  cout << "TODO" << endl;
}
