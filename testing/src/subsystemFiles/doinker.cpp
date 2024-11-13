#include "main.h"

//driver control
bool setDoinker(bool doinkerPiston){
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        if (doinkerPiston == true){
            doinker.set_value(true);  // Activate solenoid
            doinkerPiston = false;
        }else{
            doinker.set_value(false);  // Activate solenoid
            doinkerPiston = true;
        }
    }
    pros::delay(20);
    return(doinkerPiston);
}