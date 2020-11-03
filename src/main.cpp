// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Left_back            motor         11              
// Left_front           motor         2               
// Right_back           motor         3               
// Right_front          motor         13              
// Flywheel             motor         9               
// Intake1              motor         14              
// Intake2              motor         6               
// indexer              motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Left_back            motor         11              
// Left_front           motor         2               
// Right_back           motor         3               
// Right_front          motor         13              
// Flywheel             motor         9               
// Intake1              motor         14              
// Intake2              motor         7               
// indexer              motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Left_back            motor         11              
// Left_front           motor         2               
// Right_back           motor         3               
// Right_front          motor         13              
// Flywheel             motor         9               
// Intake1              motor         14              
// Intake2              motor         7               
// indexer              motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Left_back            motor         11              
// Left_front           motor         2               
// Right_back           motor         3               
// Right_front          motor         13              
// Flywheel             motor         9               
// Intake1              motor         6               
// Intake2              motor         7               
// indexer              motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "API.h"
#include "Auton_Functions.h"
using namespace vex;

// A global instance of competition
competition Competition;






void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!kiii
  vexcodeInit();
}

/*-------------------------------Autonomous--------------------------------*/

void autonomous(void)
 {// Insert autonomous user code here.
 
  Intake1.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  Intake2.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  driveInches(36, 0);
  
  indexer.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  Flywheel.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);

 
  
}

/*------------------------------User Control---------------------------------------------*/



void usercontrol(void) {// User control code here, inside the loop
  while (1) {
    Drive();
    intake();
    flywheel();
    //test
   
    
   

    //task t(Drive);
    
   
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}


// Main will set up the competition functions and callbacks.
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
