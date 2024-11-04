#include "main.h"

void testing(){
    translate(-1000, 200);
    //rotateClockWise(180,200);
}
void autoSkills(){
    intakePneumatic.set_value(true); //set intake down
    pros::delay(40);
    //clampPneumatic.set_value(true); //open clamp
    conveyorIntake(1000);
    translate(2700, 200);
    clampPneumatic.set_value(true);
    pros::delay(50);
    rotateClockWise(270, 200);
    pros::delay(10);
    translate(-3000, 200);
    pros::delay(10);
    setDrive(-80,-80);
    pros::delay(1000);
    clampPneumatic.set_value(false);
    setDrive(0,0);
    pros::delay(50);
    rotateClockWise(180, 200);
    pros::delay(200000000000000000000000);
    setConveyorMechanism(127);
    pros::delay(10);
    translate(4000, 200);
    //translate(2000, 200); //move to ring
    //rotate(90, 200);
    //translate(2000,200);
    //rotate(90, 200);
    //translate(2000, 200);
    //translate(-1000, 200);
    //rotate(90, 200);
    //translate(200,200);
    //rotate(315, 100);
    //translate(1000,200);
    //clampPneumatic.set_value(true);
    //translate(-1000, 200);




    /*intakePneumatic.set_value(true); //set intake down
    clampPneumatic.set_value(true); //open clamp
    translate(-1000, 70); //drive to stake
    clampPneumatic.set_value(false); //clamp it
    conveyorIntake(1500); //spin conveyor
    setDrive(60,-60); //turn towards corner
    pros::delay(500);
    setDrive(0,0);
    setDrive(-100,-100);
    pros::delay(5000);
    setDrive(0,0);
    clampPneumatic.set_value(true);
    translate(3000, 70);*/
}
void redLeftCorner(){
    intakePneumatic.set_value(true); //set intake down
    clampPneumatic.set_value(true); //open clamp
    translate(-6500, 65); //drive to stake
    clampPneumatic.set_value(false); //clamp
    conveyorIntake(3000); //put ring on the stake
    //rotate(90, 200);
    translate(-6500, 65);

    /*intakePneumatic.set_value(false);
    //this is for contesting the middle stake
    translate(22, 127); //go to center
    clampPneumatic.set_value(true); //clamp on stake
    conveyorIntake(3000); //put ring on the stake
    translate(2, -127); //back up a little bit
    //rotate(30, 60);// turn to face the corner
    //translate(30, 127); //drive into corner
    clampPneumatic.set_value(false); //release stake
    translate(6, -127); // drive back some more*/
}
void redRightCorner(){
    intakePneumatic.set_value(true); //set intake down
    clampPneumatic.set_value(true); //open clamp
    translate(-6500, 65); //drive to stake
    clampPneumatic.set_value(false); //clamp
    conveyorIntake(3000); //put ring on the stake
    //rotate(-90, 200);
    translate(-6500, 65);
    //translate(1, 60); //drive forward a little
    //rotate(90, 100); //trun to face the ring
    //translate(8, 127);
    //conveyorIntake(3000); // intake ring
    //clampPneumatic.set_value(false); // let of stake
    //rotate(180, 127);
    //translate(16, 127); // move to climbing bars
}
void blueLeftCorner(){
    intakePneumatic.set_value(true); //set intake down
    clampPneumatic.set_value(true); //open clamp
    translate(-6000, 65); //drive to stake
    clampPneumatic.set_value(false); //clamp
    conveyorIntake(3000); //put ring on the stake
    clampPneumatic.set_value(true); //release goal
    //translate(1, 60); //drive forward a little
    //rotate(90, 100); //trun to face the ring
    //translate(8, 127);
    //conveyorIntake(3000); // intake ring
    //clampPneumatic.set_value(false); // let of stake
    //rotate(180, 127);
    //translate(16, 127); // move to climbing bars*/
}
void blueRightCorner(){
    intakePneumatic.set_value(true); //set intake down
    clampPneumatic.set_value(true); //open clamp
    translate(-6000, 65); //drive to stake
    clampPneumatic.set_value(false); //clamp
    conveyorIntake(3000); //put ring on the stake
    clampPneumatic.set_value(true); //release goal
    /*intakePneumatic.set_value(false);
    //this is for contesting the middle stake
    clampPneumatic.set_value(false);//open up clamp
    translate(22, 127); //go to center
    clampPneumatic.set_value(true); //clamp on stake
    conveyorIntake(3000); //put ring on the stake
    translate(2, -127); //back up a little bit
    //rotate(30, 60);// turn to face the corner
    //translate(30, 127); //drive into corner
    clampPneumatic.set_value(false); //release stake
    translate(6, -127); // drive back some more*/
}