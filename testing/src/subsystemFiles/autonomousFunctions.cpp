#include "main.h"

void testing(){
    rotate(90, 55);

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
    velocityTranslate(-4050,200);
    clampPneumatic.set_value(true);
    velocityTranslate(5200, 200);
    timedTurnCC(825);
    setDriveVelocity(-200,-200);
    pros::delay(2200);
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
    velocityTranslate(-3020, 100);
    timedTurn(475);
    setDriveVelocity(-100,-100);
    pros::delay(143);
    setDriveVelocity(0,0);
    pros::delay(100);
    conveyorIntake(1000);
    pros::delay(100);
    velocityTranslate(2300, 300);
    timedTurn(800);
    pros::delay(100);
    velocityTranslate(-5500, 300);
    setDriveVelocity(-100,-100);
    pros::delay(900);
    clampPneumatic.set_value(false);
    setDriveVelocity(0,0);
    rotate(-143, 55);
    setConveyorMechanism(127);
    translate(3000,80);
    rotate(-93, 55);
    translate(1900, 80);
    rotate(-92, 55);
    translate(4200, 80);
}
void redRightCorner(){
    intakePneumatic.set_value(true); //set intake down
    clampPneumatic.set_value(true); //open clamp
}
void blueLeftCorner(){
    intakePneumatic.set_value(true); //set intake down
    clampPneumatic.set_value(true); //open clamp
    velocityTranslate(-2880, 100);
    timedTurnCC(480);
    setDriveVelocity(-100,-100);
    pros::delay(200);
    setDriveVelocity(0,0);
    pros::delay(100);
    conveyorIntake(1000);
    pros::delay(100);
    
    velocityTranslate(2300, 300);
    timedTurnCC(800);
    pros::delay(100);
    velocityTranslate(-5500, 300);
    setDriveVelocity(-100,-100);
    pros::delay(900);
    clampPneumatic.set_value(false);
    setDriveVelocity(0,0);
    rotate(143, 55);
    setConveyorMechanism(127);
    translate(3000,80);
    rotate(93, 55);
    translate(1900, 80);
    rotate(92, 55);
    translate(4200, 80);
    
}
void blueRightCorner(){
    intakePneumatic.set_value(true); //set intake down
    clampPneumatic.set_value(true); //open clamp
}