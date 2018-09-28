#include "main.h"

using namespace pros::literals;

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
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

// void opcontrol() {
// 	pros::Controller master(pros::E_CONTROLLER_MASTER);
// 	auto left_mtr = 1_mtr;
// 	pros::Motor right_mtr(2);
// 	while (true) {
// 		int left = master.get_analog(ANALOG_LEFT_Y);
// 		int right = master.get_analog(ANALOG_RIGHT_Y);
//
//
// 		left_mtr = left;
// 		right_mtr = right;
// 		pros::delay(20);
// 	}
// }


void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	auto left_mtr = 1_mtr;
	pros::Motor right_mtr(2);
	while (true) {
		int left = master.get_analog(ANALOG_LEFT_Y);
		//	int leftText = (left / 127) * 100;
		pros::lcd::set_text(1, "Left speed: " + std::to_string(left));
		int right = master.get_analog(ANALOG_RIGHT_Y);
		//	int rightText = (right / 127) * 100;
		pros::lcd::set_text(2, "Right speed: " + std::to_string(left));

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		 	right_mtr = 127;
			pros::delay(20);
		}

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			left_mtr = 127;
			pros::delay(20);
		}

		left_mtr = left;
		right_mtr = (right * -1);
		pros::delay(20);
	}
}