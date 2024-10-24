#include "main.h"

void redLeftCorner(){
    intakePneumatic.set_value(false);
    //this is for contesting the middle stake
    clampPneumatic.set_value(false);//open up clamp
    translate(22, 127); //go to center
    clampPneumatic.set_value(true); //clamp on stake
    conveyorIntake(3000); //put ring on the stake
    translate(2, -127); //back up a little bit
    //rotate(30, 60);// turn to face the corner
    //translate(30, 127); //drive into corner
    clampPneumatic.set_value(false); //release stake
    translate(6, -127); // drive back some more
}
void redRightCorner(){
    intakePneumatic.set_value(true); //set intake down
    clampPneumatic.set_value(true); //open clamp
    translate(-6000, 65); //drive to stake
    clampPneumatic.set_value(false); //clamp
    conveyorIntake(3000); //put ring on the stake
    clampPneumatic.set_value(true); //release goal
    translate(2000, 65); //evade the scene of the crime
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
    translate(2000, 65); //evade the scene of the crime
    //translate(1, 60); //drive forward a little
    //rotate(90, 100); //trun to face the ring
    //translate(8, 127);
    //conveyorIntake(3000); // intake ring
    //clampPneumatic.set_value(false); // let of stake
    //rotate(180, 127);
    //translate(16, 127); // move to climbing bars
}
void blueRightCorner(){
    intakePneumatic.set_value(false);
    //this is for contesting the middle stake
    clampPneumatic.set_value(false);//open up clamp
    translate(22, 127); //go to center
    clampPneumatic.set_value(true); //clamp on stake
    conveyorIntake(3000); //put ring on the stake
    translate(2, -127); //back up a little bit
    //rotate(30, 60);// turn to face the corner
    //translate(30, 127); //drive into corner
    clampPneumatic.set_value(false); //release stake
    translate(6, -127); // drive back some more
}