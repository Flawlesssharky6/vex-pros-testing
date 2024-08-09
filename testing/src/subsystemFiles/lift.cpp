#include "main.h"

//helper functions 
void setLift(int power){
    lift.move(power);
}

//driver control functions
void setLiftMotor(){
    //top trigger lifts, bottom trigger lowers
    int liftPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) -
    controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    setLift(liftPower);
}