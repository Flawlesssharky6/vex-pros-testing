#include "main.h"

void redLeftCorner(){
    //this is for contesting the middle stake
    translate(60, 127); //go to center
    clampPneumatic.set_value(true); //clamp on stake
    conveyorIntake(3000); //put ring on the stake
    translate(10, -127); //bakc up a little bit
    rotate(30, 60);// turn to face the corner
    translate(60, 127); //drive into corner
    clampPneumatic.set_value(false); //release stake
    translate(120, 127); // drive to climbing bars  
}
void redRightCorner(){
    translate(30, 127); //drive to stake
    clampPneumatic.set_value(true); //clamp on stake
    conveyorIntake(3000); //put ring on the stake
    translate(10, 60); //drive forward a little
    rotate(90, 100); //trun to face the ring
    translate(30, 127);
    intakePneumatic.set_value(true); //set intake down
    conveyorIntake(3000); // intake ring
    rotate(180, 127);
    clampPneumatic.set_value(false); // let of stake
    translate(70, 127); // move to climbing bars
}
void blueLeftCorner(){
    //example code
    translate(-500,100);
    rotate(-90, 127);
}
void blueRightCorner(){
    //example code
    translate(500,100);
    rotate(-90, 127);
}