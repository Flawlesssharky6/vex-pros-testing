//motors controller etc
#pragma once

//motors
//extern pros::Motor lift;
//extern pros::Motor angler;
//extern pros::Motor intakeLeft;
extern pros::Motor intake;
extern pros::Motor driveLeftBack;
extern pros::Motor driveRightBack;
extern pros::Motor driveLeftFront;
extern pros::Motor driveRightFront;
extern pros::Motor conveyor;
extern pros::Motor driveRightMiddle;
extern pros::Motor driveLeftMiddle;
//controller
extern pros::Controller controller;

//miscellaneous
extern pros::Imu gyroscope;
extern pros::ADIDigitalOut clampPneumatic;
extern pros::ADIDigitalOut intakePneumatic;
//ex: #define ANGLER_POT_VERTICAL 3000 //number for angle potentiometer for going straight
//extern pros::ADIGyro gyro;