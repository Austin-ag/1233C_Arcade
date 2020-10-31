#include "intake.h"


void intake()
{
  if(Controller1.ButtonA.pressing())
        {
        
          Intake2.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
          Intake1.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
          
        }else if(Controller1.ButtonB.pressing())
        {
        
          Intake1.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
          Intake2.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
          
        }else
        {
          Intake1.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
          Intake2.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
          Intake1.setStopping(vex::brakeType::hold);
          Intake2.setStopping(vex::brakeType::hold);
          
          
        }
         
  if(Controller1.ButtonR1.pressing())
  {
    indexer.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);

  }else if(Controller1.ButtonL1.pressing())
  {
    indexer.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);

  }else
  {
    indexer.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
    indexer.setStopping(vex::brakeType::hold);
    
  }
      

  
}