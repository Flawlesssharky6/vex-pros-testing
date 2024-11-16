#include "main.h"

//helper functions
void setLadyBrownMechanism(int power){
ladyBrownMotor.move(power);
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

//driver macros
void resetLadyBrown(){

}

void prepareLadyBrown(){
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)){
        if(rotationSensor.get_position() < 1800){
            setLadyBrownMechanism(127);
            while (rotationSensor.get_position() < 1800 && !controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)){
                pros::delay(20);
            }
        }else if (rotationSensor.get_position() > 1800){
            setLadyBrownMechanism(-127);
            while (rotationSensor.get_position() > 1800 && !controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)){
                pros::delay(20);
            }
        }
        setLadyBrownMechanism(0);
    }
    
}

/*
void prepareLadyBrown(void* param) {
    while (true) { // Ensure the task can run continuously or until manually stopped
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            if (rotationSensor.get_position() < 1800) {
                setLadyBrownMechanism(127);
                while (rotationSensor.get_position() < 1800 && !controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
                    pros::delay(20);
                }
            } else if (rotationSensor.get_position() > 1800) {
                setLadyBrownMechanism(-127);
                while (rotationSensor.get_position() > 1800 && !controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
                    pros::delay(20);
                }
            }
            setLadyBrownMechanism(0);
        }
        pros::delay(50); // Prevent the loop from running excessively fast
        pros::lcd::set_text(5, "complete");
    }
}
*/
void extendLadyBrown(){

}

//autonomous functions
void turnLadyBrownMotor(){
    rotationSensor.reset();
    double targetAngleChange = 100;
    //get_angle returns in centidegrees (0-36000)
    //spin up
    while (rotationSensor.get_angle()< targetAngleChange*100){ //convert to centidegrees
        ladyBrownMotor.move_velocity(100);
        pros::delay(20);
    }
    ladyBrownMotor.brake();
    ladyBrownMotor.move_velocity(0);
    pros::delay(50);
    rotationSensor.reverse();
    //spin down
    while (rotationSensor.get_angle()> 5000){
        ladyBrownMotor.move_velocity(-100);
        pros::delay(20);
    }
    ladyBrownMotor.brake();
    ladyBrownMotor.move_velocity(0);
    pros::delay(50);
}
