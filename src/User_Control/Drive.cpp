#include "Drive.h"
//using namespace vex;

void Drive()
{


    int deadband = 15;

 
    // Get the velocity percentage of the left motor. (Axis3 + Axis1)
    int leftMotorSpeed = Controller1.Axis3.position() + Controller1.Axis4.position();
    // Get the velocity percentage of the right motor. (Axis3 - Axis1)
    int rightMotorSpeed = Controller1.Axis3.position() - Controller1.Axis4.position();

    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband && abs(Controller1.Axis2.position()) < deadband)
    {
      // Set the speed to zero.
      Left_back.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
      Left_front.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
    } 
    else if(abs(Controller1.Axis2.position()) > deadband)
    {
      Left_back.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
      Left_front.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);

    }
    else 
    {
      // Set the speed to leftMotorSpeed
      Left_back.spin(vex::directionType::fwd, leftMotorSpeed, vex::velocityUnits::pct);
      Left_front.spin(vex::directionType::fwd, leftMotorSpeed, vex::velocityUnits::pct);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(rightMotorSpeed) < deadband && abs(Controller1.Axis2.position()) < deadband) 
    {
      // Set the speed to zero
      Right_back.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
      Right_front.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
    } 
    else if(abs(Controller1.Axis2.position()) > deadband)
    {
      Right_back.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
      Right_front.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);

    }
    else 
    {
      // Set the speed to rightMotorSpeed
      Right_back.spin(vex::directionType::fwd, rightMotorSpeed, vex::velocityUnits::pct);
      Right_front.spin(vex::directionType::fwd, rightMotorSpeed, vex::velocityUnits::pct);
    }

 
}
