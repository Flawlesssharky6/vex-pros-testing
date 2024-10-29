#include "main.h"

//helper functions
void setLadyBrownMechanism(int power){
ladyBrownMotor.move(power);
ladyBrownMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

//driver functions
void setLadyBrownMotor(){
    //up button swings up, down button swings down
    //get_digital returns boolean (0 or 1)
    //up button - bottom button
    int motorPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)
    - controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN));
    setLadyBrownMechanism(motorPower);
    pros::delay(20);
}