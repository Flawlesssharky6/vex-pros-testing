//motors controller etc
#pragma once

//motors
extern pros::Motor lift;
extern pros::Motor angler;
extern pros::Motor intakeLeft;
extern pros::Motor intakeRight;
extern pros::Motor driveLeftBack;
extern pros::Motor driveRightBack;
extern pros::Motor driveLeftFront;
extern pros::Motor driveRightFront;
//controller
extern pros::Controller controller;

//miscellaneous
//ex: #define ANGLER_POT_VERTICAL 3000 //number for angle potentiometer for going straight
extern pros::ADIGyro gyro;