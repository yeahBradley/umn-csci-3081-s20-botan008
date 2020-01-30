#include <iostream>
#include "robot.h"

int main() {
  Robot rosy_robot;
  Robot c3po_robot(100,100);
  Robot hal_robot(3.14);
  Robot eva_robot(-100,-100,-3.14/4);
  rosy_robot.Display();
  c3po_robot.Display();
  hal_robot.Display();
  eva_robot.Display();


  // Robot rosy_robot;
  // rosy_robot.Display();

  // Robot c3po_robot(10,20,2.8);
  // c3po_robot.Display();

  // rosy_robot.set_position(0, 0);
  // rosy_robot.set_direction_angle_rad(0);
  // rosy_robot.Display();
}
