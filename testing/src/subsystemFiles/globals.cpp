#include "main.h"

//motors
//pros::Motor lift(-19, pros::v5::MotorGears::green, pros::v5::MotorUnits::counts);//negative int for reverse motor
//pros::Motor angler(-21, pros::v5::MotorGears::green, pros::v5::MotorUnits::counts);
//pros::Motor intakeLeft(-3, pros::v5::MotorGears::green, pros::v5::MotorUnits::counts);
pros::Motor intake(-9, pros::v5::MotorGears::rpm_200, pros::v5::MotorUnits::counts);
pros::Motor driveLeftBack(-20, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveLeftFront(-11, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveRightBack(10, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveRightFront(1, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor conveyor(4, pros::v5::MotorGears::rpm_200, pros::v5::MotorUnits::counts);
pros::Motor driveLeftMiddle(-16, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveRightMiddle(6, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor ladyBrownMotor(-18, pros::v5::MotorGears::red, pros::v5::MotorUnits::counts);
//controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//sensors
pros::Imu gyroscope(19);
pros::Rotation rotationSensor(3);
//pneumatics
pros::ADIDigitalOut clampPneumatic('H');
pros::ADIDigitalOut intakePneumatic('G');
