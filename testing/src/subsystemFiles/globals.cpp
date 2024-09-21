#include "main.h"

//motors
//pros::Motor lift(-19, pros::v5::MotorGears::green, pros::v5::MotorUnits::counts);//negative int for reverse motor
//pros::Motor angler(-21, pros::v5::MotorGears::green, pros::v5::MotorUnits::counts);
pros::Motor intakeLeft(-3, pros::v5::MotorGears::green, pros::v5::MotorUnits::counts);
pros::Motor intakeRight(4, pros::v5::MotorGears::green, pros::v5::MotorUnits::counts);
pros::Motor driveLeftBack(-5, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveLeftFront(-6, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveRightBack(7, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveRightFront(8, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor conveyor(9, pros::v5::MotorGears::green, pros::v5::MotorUnits::counts);
pros::Motor driveLeftMiddle(-10, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveRightMiddle(11, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
//controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//miscellaneous
pros::Imu gyroscope(20);