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
extern pros::Motor ladyBrownMotor;
//controller
extern pros::Controller controller;

//sensors
extern pros::Imu gyroscope;
extern pros::Rotation rotationSensor;
//pneumatics
extern pros::ADIDigitalOut clampPneumatic;
extern pros::ADIDigitalOut intakePneumatic;
extern pros::ADIDigitalOut doinker;
//ex: #define ANGLER_POT_VERTICAL 3000 //number for angle potentiometer for going straight
//extern pros::ADIGyro gyro;