
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
    fabs(driveRightBack.get_position()) +
    fabs(driveLeftMiddle.get_position()) +
    fabs(driveRightMiddle.get_position())/ 6);
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
//10 inches should be about 417 units
void translate(double units, int velocity) {
    // Determine direction based on the sign of units
    int direction = abs(units) / units;

    // Reset drive encoders and tare the gyroscope
    resetDriveEncoders();
    gyroscope.tare_heading();

    // Drive forward or backward until the target units are reached
    while (avgDriveEncoderValue() < fabs(units)) {
        // Apply drive power, adjusting slightly based on gyroscope correction if necessary
        setDrive(velocity * direction, velocity * direction);
        pros::delay(10);
    }

    // Brief brake to prevent overshoot
    setDrive(-10 * direction, -10 * direction);
    pros::delay(10);  // Adjust depending on robot weight for optimal stopping

    // Final stop to ensure full stop and correct position if overshoot
    setDrive(0, 0);
    pros::delay(50);

    // Correction for overshoot or undershoot
    int finalEncoderValue = avgDriveEncoderValue();
    if (finalEncoderValue > fabs(units)) {
        // Reverse slightly to correct overshoot
        setDrive(-0.1 * velocity * direction, -0.1 * velocity * direction);
        while (avgDriveEncoderValue() > fabs(units)) {
            pros::delay(10);
        }
    } else if (finalEncoderValue < fabs(units)) {
        // Move forward slightly to correct undershoot
        setDrive(0.1 * velocity * direction, 0.1 * velocity * direction);
        while (avgDriveEncoderValue() < fabs(units)) {
            pros::delay(10);
        }
    }

    // Final drive stop
    setDrive(0, 0);
    pros::delay(20);
}


void rotateClockWise(int degrees, int velocity) {
    // Define rotation direction based on the sign of the input degrees
    int direction = abs(degrees) / degrees;
    int targetHeading = fabs(gyroscope.get_heading()) + abs(degrees);

    // Start turning at the specified velocity
    setDrive(velocity * direction, -velocity * direction);

    // Continue turning until the heading is close to the target
    while (fabs(gyroscope.get_heading()) < targetHeading - 5) { // Adjusted to reduce overshoot
        pros::delay(20);
    }

    // Stop drive to let robot lose momentum
    setDrive(0, 0);
    pros::delay(100); // Allow some time for robot to fully stop

    // Correct for any overshoot or undershoot
    int finalHeading = fabs(gyroscope.get_heading());
    if (finalHeading > targetHeading) {
        // Slight counter-turn to correct overshoot
        setDrive(-0.1 * velocity * direction, 0.1 * velocity * direction);
        while (fabs(gyroscope.get_heading()) > targetHeading) {
            pros::delay(20);
        }
    } else if (finalHeading < targetHeading) {
        // Slight turn to correct undershoot
        setDrive(0.1 * velocity * direction, -0.1 * velocity * direction);
        while (fabs(gyroscope.get_heading()) < targetHeading) {
            pros::delay(20);
        }
    }

    // Ensure drive is stopped at the end
    setDrive(0, 0);
}

void timedTurn(int millisec){
    setDrive(200,-200);
    pros::delay(millisec);
    setDrive(0,0);
}