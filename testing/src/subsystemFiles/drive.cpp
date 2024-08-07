#include "main.h"


//helper functions
void setDrive(int left, int right){
    driveLeftBack.move(left);
    driveLeftFront.move(left);
    driveRightBack.move(right);
    driveRightFront.move(right);
}

//driver control functions
void setDriveMotors(){
    //tank drive
    int leftJoyStick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightJoyStick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    //set dead zone for joystick
    if(abs(leftJoyStick) < 10){
        leftJoyStick = 0;
    }
    if(abs(leftJoyStick) < 10){
        rightJoyStick = 0;
    }
    setDrive(leftJoyStick, rightJoyStick);
}