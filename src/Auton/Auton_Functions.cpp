#include "Auton_Functions.h"

//test

void MoveForward(float distance, float speed)//Auton Function:Move Forward
{
 

  Right_back.setVelocity(speed, vex::percentUnits::pct);
  Right_front.setVelocity(speed, vex::percentUnits::pct);
  Left_back.setVelocity(speed, vex::percentUnits::pct);
  Left_front.setVelocity(speed, vex::percentUnits::pct);

  Right_front.rotateTo(distance, vex::rotationUnits::deg,false);
  Left_front.rotateTo(distance, vex::rotationUnits::deg,false);
  Left_back.rotateTo(distance, vex::rotationUnits::deg, false);
  Right_back.rotateTo(distance, vex::rotationUnits::deg);

  Right_back.resetRotation();
  Right_front.resetRotation();
  Left_back.resetRotation();
  Left_front.resetRotation();
  
  
  
} 

void MoveBackward(float distancee,  float speed)//Auton Function:Move backword
{
   

  Right_back.setVelocity(-speed, vex::percentUnits::pct);
  Left_back.setVelocity(-speed, vex::percentUnits::pct);
  Left_front.setVelocity(-speed, vex::percentUnits::pct);
  Right_front.setVelocity(-speed, vex::percentUnits::pct);

  Right_front.rotateTo(distancee, vex::rotationUnits::deg,false);
  Left_front.rotateTo(distancee, vex::rotationUnits::deg,false);
  Left_back.rotateTo(distancee, vex::rotationUnits::deg,false);
  Right_back.rotateTo(distancee, vex::rotationUnits::deg);

  Right_back.resetRotation();
  Right_front.resetRotation();
  Left_back.resetRotation();
  Left_front.resetRotation();
}


void TurnRight(float distance,  float speed)//Auton Function:Turn Right
{
  

  Right_back.setVelocity(speed, vex::percentUnits::pct);
  Right_front.setVelocity(speed, vex::percentUnits::pct);
  Left_back.setVelocity(speed, vex::percentUnits::pct);
  Left_front.setVelocity(speed, vex::percentUnits::pct);

  Right_front.rotateTo(-distance, vex::rotationUnits::deg,false);
  Right_back.rotateTo(-distance, vex::rotationUnits::deg,false);
  Left_front.rotateTo(distance, vex::rotationUnits::deg,false);
  Left_back.rotateTo(distance, vex::rotationUnits::deg);

  Right_back.resetRotation();
  Right_front.resetRotation();
  Left_back.resetRotation();
  Left_front.resetRotation();
}

void TurnLeft(float distance,  float speed)//Auton Function:turn left
{
  Right_back.setVelocity(speed, vex::percentUnits::pct);
  Right_front.setVelocity(speed, vex::percentUnits::pct);
  Left_back.setVelocity(-speed, vex::percentUnits::pct);
  Left_front.setVelocity(-speed, vex::percentUnits::pct);
  vex::wait(100, msec);

  Right_front.rotateTo(distance, vex::rotationUnits::deg,false);
  Right_back.rotateTo(distance, vex::rotationUnits::deg,false);
  Left_front.rotateTo(distance, vex::rotationUnits::deg,false);
  Left_back.rotateTo(distance, vex::rotationUnits::deg);

  //Right_front,Right_back.rotateTo(distance, vex::rotationUnits::deg);
}


int ten;

void driveInches(float inches , float direction)//drive forward with pid
{
  
  float target = (inches / (4 * M_PI)) * 360;
    //int target = inches;
  float KDECL = 4;
  int lAvgTicks = 0;
  int rAvgTicks = 0;
  int avgTicks = 0;
  float currentPower = 0;
  float lPower = 0;
  float rPower = 0;
  //float iPower = 0;
  float distErr = 0;
  float alignErr = 0;
  float distKp = 0.5;
  float alignKp = 0.15;
  
  const float SLEW = .003;//AKA the acceleration in rpm/cycle ***SHOULD BE .003***

  while(avgTicks < target)
  {
     


    lAvgTicks = fabs(/*(Left_front.position(degrees) +*/ Left_back.position(degrees))   ;//divide by 2(avreage)
    rAvgTicks = fabs(/*(Right_front.position(degrees) +*/ Right_back.position(degrees))  ;

    avgTicks = abs(lAvgTicks + rAvgTicks) / 2;

    distErr = (target - avgTicks) * distKp;

    if(distErr > SLEW)
    {
      distErr = SLEW;
    }


    if(currentPower * KDECL > (target - avgTicks))
    {
      //iPower += (target - avgTicks) * distKi;
      distErr = (distErr * -1);

    }


     //Decide which side is too far ahead, apply alignment and speed corretions
    alignErr = abs((lAvgTicks - rAvgTicks)) * alignKp;

    if(lAvgTicks > rAvgTicks)
    {
      lPower = (currentPower + distErr) - alignErr;
      rPower = currentPower + distErr;
    }
    else if(rAvgTicks > lAvgTicks)
    {
      rPower = (currentPower + distErr) - alignErr;
      lPower = currentPower + distErr;
    }
    else
    {
      lPower = currentPower + distErr;
      rPower = currentPower + distErr;
    }


    //Check what direction we should go, change motor velocities accordingly
    if(direction == 1)
    {
      lPower = lPower * -1;
      rPower = rPower * -1;
    }


     //Send velocity targets to both sides of the drivetrain
    //setDriveSideVel(lPower, 'l');
    //setDriveSideVel(rPower, 'r');
    

    Left_front.spin(vex::directionType::fwd, lPower, vex::velocityUnits::pct);
    Left_back.spin(vex::directionType::fwd, lPower, vex::velocityUnits::pct);

    Right_front.spin(vex::directionType::fwd, rPower, vex::velocityUnits::pct);
    Right_back.spin(vex::directionType::fwd, rPower, vex::velocityUnits::pct);

      //Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print(avgTicks);

    Brain.Screen.setCursor(2,2);
    Brain.Screen.print(Left_front.position(degrees));
     

    //Set current power for next cycle, make sure it doesn't get too high/low
    /*As a side note, the distance(in ticks) at which deceleration starts is
      determined by the upper limit on currentPower*/
    currentPower = currentPower + distErr;
    if(currentPower > 200)
    {
      currentPower = 200;
    }
    else if(currentPower < 0)
    {
      currentPower = 0;
    }


    
}

    Left_front.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
    Left_back.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);

    Right_front.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
    Right_back.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);

  //stopAll();
  //return;
}


