#include "main.h"

void testing(){
    translate(1000, 84);
    rotate(90, 60);
    rotate(-90, 60);
    //translate(-1000, 200);
    //rotateClockWise(180,200);
}


void autoSkills(){
    //make sure it is using .move_velocity()/velocityTranslate/setDeriveVeocity
    intakePneumatic.set_value(true); //set intake down
    pros::delay(40);
    conveyorIntake(1000);
    velocityTranslate(2700, 200);
    clampPneumatic.set_value(true);
    timedTurn(475);
    setDriveVelocity(-200,-200);
    pros::delay(200);
    setDriveVelocity(-100,-100);
    pros::delay(1000);
    clampPneumatic.set_value(false);
    timedTurn(940);
    setConveyorMechanism(127);
    velocityTranslate(9100, 200);
    velocityTranslate(-4100, 200);
    timedTurnCC(200);
    velocityTranslate(2000, 200);
    timedTurnCC(830);
    velocityTranslate(-4150,200);
    clampPneumatic.set_value(true);
    velocityTranslate(5400, 200);
    timedTurnCC(860);
    setDriveVelocity(-200,-200);
    pros::delay(2300);
    setDriveVelocity(-100,-100);
    pros::delay(200);
    clampPneumatic.set_value(false);
    setDriveVelocity(0,0);
    timedTurn(950);
    velocityTranslate(9000, 200);
    timedTurnCC(800);
    velocityTranslate(-5000,200);
    clampPneumatic.set_value(true);
    velocityTranslate(2000, 200);
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