
#include "main.h"



//driver control
void setPneumaticPiston(){
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        pneumatic.set_value(true);  // Activate solenoid
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        pneumatic.set_value(false);  // Deactivate solenoid
    }
    pros::delay(20);
}
