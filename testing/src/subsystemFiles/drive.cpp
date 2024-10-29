#include "main.h"

//note: change gyro from ADI to IMU
//pros::ADIGyro gyro(20);
//pros::ADIGyro gyro('B', 0.91); //second parameter is angler scaler in case gyro is off 
//you can leave the scaler off (ex: if you turn 90 degrees but gyro returns 800)
//when turn left gyro value is positive, and turn right is negative
//if values gyro values are flipped then switch wires so three pins are plugged in opposite way

//helper functions
void setDrive(int left, int right){
    driveLeftBack.move_velocity(left);
    driveLeftFront.move_velocity(left);
    driveRightBack.move_velocity(right);
    driveRightFront.move_velocity(right);
    driveRightMiddle.move_velocity(right);
    driveLeftMiddle.move_velocity(left);
}

void setDriveDriver(int left, int right){ //when on move_velocity, driver control is really weird
    driveLeftBack.move(left);
    driveLeftFront.move(left);
    driveRightBack.move(right);
    driveRightFront.move(right);
    driveRightMiddle.move(right);
    driveLeftMiddle.move(left);
}

void resetDriveEncoders(){
    driveLeftBack.tare_position();
    driveLeftFront.tare_position();
    driveRightBack.tare_position();
    driveRightFront.tare_position();
    driveRightMiddle.tare_position();
    driveLeftMiddle.tare_position();
}

double avgDriveEncoderValue(){
    return (fabs(driveLeftFront.get_position()) +
    fabs(driveLeftBack.get_position()) +
    fabs(driveRightFront.get_position()) +
    fabs(driveRightBack.get_position())) +
    fabs(driveLeftMiddle.get_position()) +
    fabs(driveRightMiddle.get_position())/ 4;
}

//driver control functions
void setDriveMotors(){
    //Stick drive
    int power = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    //set dead zone for joystick
    if(abs(power) < 10){
        power = 0;
    }
    if(abs(turn) < 10){
        turn = 0;
    }
    int leftSpeed = power + turn;
    int rightSpeed = power - turn;
    setDriveDriver(leftSpeed, rightSpeed);
}

//autonomous functions
// 1 unit = 1 rotation of the wheel = circumfrence of wheel
void translate(int units, int velocity){
    //define direction based on units provided
    int direction = abs(units)/units; //either 1 or -1
    //reset motor encoders (I want to try to add to current units instead of reseting)
    resetDriveEncoders();
    gyroscope.tare_heading();
    //drive forward until units are reached
    while(avgDriveEncoderValue() < fabs(units)){
        setDrive(velocity * direction, velocity * direction); //scale gyroscope heading if over or under correcting
        //generally don't have to worry about over correcting
        pros::delay(10);
    }
    //brief brake
    setDrive(-10 * direction,-10 * direction);
    pros::delay(50);//change millisec depending on weight of robot
    //set drive back to nuetral
    setDrive(0,0);
}

void rotate(int degrees, int velocity){
    //define direction based on the units provided
    //if turn left use positive number, if right use negative number
    //degrees = degrees *.75;
    int direction = abs(degrees)/degrees;
    int currentHeading = fabs(gyroscope.get_heading());
    //turn intil units are reached
    setDrive(velocity * direction, -velocity * direction);
    //turn until units - 5 degrees is reached
    while(fabs(gyroscope.get_heading()) < (abs(degrees)+currentHeading)-5){ //subract a little from target degrees to anticipate over turning (hopefully saves time)
        pros::delay(10);
    }
    //let robot lose momentum
    setDrive(0,0);
    //pros::delay(100); //wait until the robot completely stops (based on weight)
    //correct over or under shoot
    /*if(fabs(gyroscope.get_heading()) > abs(degrees)){
        setDrive(.5 * voltage * direction, .5 * -voltage * direction);
        while(fabs(gyroscope.get_heading()) > abs(degrees)){
            pros::delay(10);
        } 
    }else if (fabs(gyroscope.get_heading()) < abs(degrees)){
        setDrive(.5 * -voltage * direction, .5 * voltage * direction);
        while(fabs(gyroscope.get_heading()) < abs(degrees) - 5){ //subract a little from target degrees to anticipate over turning (hopefully saves time)
            pros::delay(10);
        }
    }
    //reset drive to zero
    setDrive(0,0);*/
}