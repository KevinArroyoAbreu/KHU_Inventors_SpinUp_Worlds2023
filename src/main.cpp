#include "main.h"
#include "autonSelection.h"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	def::Flywheel.setGearing(AbstractMotor::gearset::blue);
	def::inertial.tare_rotation();
	def::inertial.set_heading(1);
	selector::init(); 
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
void competition_initialize() {

}

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
	//lower angle
   angleDown();
   //set drive to Brake
   setDriveBrake();

/*selector::auton == 1 : Roller
selector::auton == 2 : extraRoller
selector::auton == 3 : Skills
selector::auton == -1 : Non roller
selector::auton == -2 : extraNon roller
selector::auton == -3 : N/a
selector::auton == 0 : Full Wp*/

if(selector::auton == 1){ //Roller
 rollerAuton();
}
if(selector::auton == 2){ //extraRoller
 
}
if(selector::auton == 3){ //full WP
fullWpAuton();
}
if(selector::auton == -1){ //Non roller
 nonRollerAuton();
}
if(selector::auton == -2){ //extraNon roller
 nonRollerExtraAuton();
}
if(selector::auton == -3){ //N/a Skillshort
 progSkillsShort();
}
if(selector::auton == 0){ //Skills
 progSkills();
}


	//setDriveBrake();
	//runAuton();
}

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
void opcontrol() {
	setDriveCoast();
	runOp();
}
