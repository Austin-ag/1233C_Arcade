#include "flywheel.h"


void flywheel()
{
 if(Controller1.ButtonL2.pressing())
      {
       
        Flywheel.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
        
         
      }else if(Controller1.ButtonR2.pressing())
      {
        
        Flywheel.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        
      }else if(Controller1.ButtonY.pressing())
      {
        Flywheel.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
        Flywheel.setStopping(vex::brakeType::hold);
         
      }


 
}