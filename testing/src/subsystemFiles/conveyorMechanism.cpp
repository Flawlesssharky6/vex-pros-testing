#include "main.h"

//helper functions
void setConveyorMechanism(int power){
    conveyor.move(power);
    intake.move(power);
}

//driver control functions
void setConveyorMotors(){
    //bottom trigger intakes, top trigger outtakes
    //get_digital returns boolean (0 or 1)
    //bottom triggers - top triggers
    int motorPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)
    - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));

    setConveyorMechanism(motorPower);
}

//autonomous functions
void conveyorIntake(int millisec){
    setConveyorMechanism(127);
    pros::delay(millisec);
    setConveyorMechanism(-5);
    pros::delay(50);
    setConveyorMechanism(0);
}
void conveyorOuttake(int millisec){
    setConveyorMechanism(-127);
    pros::delay(millisec);
    setConveyorMechanism(5);
    pros::delay(50);
    setConveyorMechanism(0);
}
