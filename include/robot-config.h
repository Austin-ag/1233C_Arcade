using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Left_back;
extern motor Left_front;
extern motor Right_back;
extern motor Right_front;
extern motor Flywheel;
extern motor Intake1;
extern motor Intake2;
extern motor indexer;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );