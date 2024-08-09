#include "main.h"

pros::ADIPotentiometer anglerPot('A'); //port A

//helper functions
void setAngler(int power){
    angler.move(power);
}

//driver control functions
void setAnglerMotor(){
    //up arrow goes up, down arrow goes down
    int anglerPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP) - 
    controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN));
    setAngler(anglerPower);
}