#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "hello");
	pros::lcd::set_text(2, "Hello");

	//pros::lcd::register_btn1_cb(on_center_button);
	
	//motor breaks
	driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	driveRightMiddle.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	driveLeftMiddle.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	//lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	//angler.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	//intakeLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	conveyor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	ladyBrownMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	//pneumatic.set_value(false);
	rotationSensor.reset_position();
	rotationSensor.set_reversed(true);
	gyroscope.reset();
	//pros::ADIGyro gyro('B', .091);
	pros::delay(2000); //give it 2 sec to calibrate
	//don't start autonomous until at least 2 seconds after controller is connected
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	//uncomment the run case
	testing();
	//autoSkills();
	//redLeftCorner();
	//redRightCorner();
	//blueLeftCorner();
	//blueLeftCorner();
	//conveyorIntake(500);
	//conveyorOuttake(500);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size 3 the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	bool doinkerPiston = false;
	while(true){
		pros::lcd::set_text(3, std::to_string(gyroscope.get_heading()));
		pros::lcd::set_text(4, std::to_string(rotationSensor.get_position()));
		//control drive
		//gyroscope.get_heading();
		setDriveMotors();
		setPneumaticPiston();
		setConveyorMotors();
		setIntakePneumatic();
		setLadyBrownMotor();

		prepareLadyBrown();

		doinkerPiston = setDoinker(doinkerPiston);
		//control intake
		//setIntakeMotors();

		//control lift
		//setLiftMotor();

		//control angler
		//setAnglerMotor();

		//control conveyor motor
		//setConveyorMotor();
		pros::delay(10);//motors update voltage values every 10 millisec
	}
}