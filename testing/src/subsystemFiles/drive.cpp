#include "main.h"

pros::ADIGyro gyro('B', 0.91); //second parameter is angler scaler in case gyro is off 
//you can leave the scaler off (ex: if you turn 90 degrees but gyro returns 800)
//when turn left gyro value is positive, and turn right is negative
//if values gyro values are flipped then switch wires so three pins are plugged in opposite way

//helper functions
void setDrive(int left, int right){
    driveLeftBack.move(left);
    driveLeftFront.move(left);
    driveRightBack.move(right);
    driveRightFront.move(right);
}

void resetDriveEncoders(){
    driveLeftBack.tare_position();
    driveLeftFront.tare_position();
    driveRightBack.tare_position();
    driveRightFront.tare_position();
}

double avgDriveEncoderValue(){
    return (fabs(driveLeftFront.get_position()) +
    fabs(driveLeftBack.get_position()) +
    fabs(driveRightFront.get_position()) +
    fabs(driveRightBack.get_position())) / 4;
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

//autonomous functions
void translate(int units, int voltage){
    //define direction based on units provided
    int direction = abs(units)/units; //either 1 or -1
    //reset motor encoders (I want to try to add to current units instead of reseting)
    resetDriveEncoders();
    gyro.reset();
    //drive forward until units are reached
    while(avgDriveEncoderValue() < fabs(units)){
        setDrive(voltage * direction + gyro.get_value(), voltage * direction - gyro.get_value()); //scale gyro value if over or under correcting
        //genrally don't have to worry about over correcting
        pros::delay(10);
    }
    //brief brake
    setDrive(-10 * direction,-10 * direction);
    pros::delay(50);//change millisec depending on weight of robot
    //set drive back to nuetral
    setDrive(0,0);
}

void rotate(int degrees, int voltage){
    //define direction based on the units provided
    //if turn left use positive number, if right use negative number
    int direction = abs(degrees)/degrees;
    //resetting the gyro
    gyro.reset();
    //turn intil units are reached
    setDrive(-voltage * direction, voltage * direction);
    //turn until units - 5 degrees is reached
    while(fabs(gyro.get_value()) < abs(degrees*10) - 50){ //subract a little from target degrees to anticipate over turning (hopefully saves time)
        pros::delay(10);
    }
    //let robot lose momentum
    setDrive(0,0);
    pros::delay(100); //wait until the robot completely stops (based on weight)
    //correct over or under shoot
    if(fabs(gyro.get_value()) > abs(degrees * 10)){
        setDrive(.5 * voltage * direction, .5 * -voltage * direction);
        while(fabs(gyro.get_value()) > abs(degrees*10)){
            pros::delay(10);
        } 
    }else if (fabs(gyro.get_value()) < abs(degrees*10)){
        setDrive(.5 * -voltage * direction, .5 * voltage * direction);
        while(fabs(gyro.get_value()) < abs(degrees*10) - 50){ //subract a little from target degrees to anticipate over turning (hopefully saves time)
            pros::delay(10);
        }
    }
    //reset drive to zero
    setDrive(0,0);
}