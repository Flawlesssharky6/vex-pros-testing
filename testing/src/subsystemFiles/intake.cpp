/*
#include "main.h"

//helper function
void setIntake(int power){
    intakeLeft.move(power);
    intakeRight.move(power);
}

//driver control functions
void setIntakeMotors(){
    //bottom trigger intakes, top trigger outtakes
    //get_digital returns boolean (0 or 1)
    //bottom triggers - top triggers
    int intakePower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)
    - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
    setIntake(intakePower);
}
*/