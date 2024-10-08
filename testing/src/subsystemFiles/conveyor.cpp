/*
#include "main.h"

//helper functions
void setConveyor(int power){
    conveyor.move(power);
}

//driver controll functions
void setConveyorMotor(){
    //bottom trigger intakes, top trigger outtakes
    //get_digital returns boolean (0 or 1)
    //bottom triggers - top triggers
    int conveyorPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)
    - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1));

    setConveyor(conveyorPower);
}

//autonomous functions
void conveyorIntake(int millisec){
    setConveyor(127);
    pros::delay(millisec);
    setConveyor(-5);
    pros::delay(50);
    setConveyor(0);
}
void conveyorOuttake(int millisec){
    setConveyor(-127);
    pros::delay(millisec);
    setConveyor(5);
    pros::delay(50);
    setConveyor(0);
}
*/