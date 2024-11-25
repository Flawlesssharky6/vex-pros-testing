#pragma once

//helper functions
void setConveyorMechanism(int power);

//driver control functions
void setConveyorMotors();
void setIntakePneumatic();

//autonomous functions
void conveyorIntake(int millisec);
void conveyorOuttake(int millisec);