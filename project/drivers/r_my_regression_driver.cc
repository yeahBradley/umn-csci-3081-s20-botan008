#include <ctime>
#include <iostream>
#include <fstream>
#include <random>
#include <string>

#include "r_my_local_simulator.h"

/* This regression test implements the second suggestion from Lab13.
 * It generates (stop.id_ + 1) passengers at each generate phase.
 *
 *
 */

int main() {

  int rounds = 50; //Number of rounds of generation to simulate in test

  srand((long)1); //Seed the random number generator with the same seed every time!


  rMyLocalSimulator my_sim;

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "         STARTING" << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "*************************/" << std::endl;

  my_sim.Start();

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "           BEGIN" << std::endl;
  std::cout << "          UPDATING" << std::endl;
  std::cout << "*************************/" << std::endl;

  for (int i = 0; i < rounds; i++) {
	  my_sim.Update();
  }

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "         COMPLETE" << std::endl;
  std::cout << "*************************/" << std::endl;


  return 0;
}
