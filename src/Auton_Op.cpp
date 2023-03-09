//*****************************************************************
// Auton-Op.cpp
//-----------------------------------------------------------------
/*This file contains Autonomous and Operator Control tasks.*/
//*****************************************************************


//Include all header files
#include "main.h"
//___________________________________________________\\



void runAuton(){
   //lower angle
   angleDown();
  /*------------------------------------------*/
  //SELECTED AUTON ROUTINE:
  /*------------------------------------------*/
  //turnPID(-90);
//  drive->moveDistance(24_in);
//  turnPID(90);
     rollerAuton();
  //   nonRollerAuton();
  //   fullWpAuton();
  //   progSkills();
  //   progSkillsPID();

//  while(1)
//  {
//    pros::screen::print(TEXT_LARGE, 3, "Inertial: %f", def::inertial.get_heading());
//    pros::delay(20);
//  }
}


void runOp(){
  //set brake mode to coast

  setDriveCoast();
  pros::screen::erase();

while(true){
  //pros::screen::print(TEXT_LARGE, 3, "Flywheel: %f", def::Flywheel.getActualVelocity());
/*------------------------------------------*/
    //Drivetrain movement; Operator Control:
/*------------------------------------------*/

//Control Drivetrain with left joystick (drive) and right joystick(turn)
//--DRIVETRAIN CONTROL FUNCTIONS
//Drivetrain Movements (Op Control) (p. 24 subsystem#5)
int fwdJoystick = pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y);
int turnJoystick = pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_X);
//b(x) = x^2
int fwdMovementFunct = 2*fwdJoystick; //(full speed at half joystick)
int turnMovementFunct = turnJoystick;
///////////////////////////////////////////////////////////////////////////
    //lift angle Changer
   angleUp();

    //LEFT
   pros::c::motor_move(11, fwdMovementFunct + turnMovementFunct);
   pros::c::motor_move(12, - fwdMovementFunct - turnMovementFunct);
    //RIGHT
   pros::c::motor_move(13, - fwdMovementFunct + turnMovementFunct);
   pros::c::motor_move(14, fwdMovementFunct - turnMovementFunct);


/*------------------------------------------*/
//Shooter; Operator Control:
/*------------------------------------------*/
if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
  angleUp();
  flySpinToV(360);//350 (hard shooting)
}
else if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1) {
  angleUp();
  flySpinToV(600);
}
else if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == 1) {
  angleDown();
  flySpinToV(410);
}
else{
  angleUp();
  flySpinToV(330);//mantain momentum (normal shooting) 330
}

/*------------------------------------------*/
//Intake and Roller Spinner; Operator Control:
/*------------------------------------------*/
//Intake + Shoot and Roller + Angle Changer
if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
  shoot();
}
else if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) {
  intakeV(500);
//  rollerV(-200);
}
else if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
  intakeV(-500);
}
else{
  intakeStop();
  pros::c::motor_move(10, pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_Y)*(2));
  pros::delay(20);//prevent data loss
}
/*------------------------------------------*/
//Expansion; Operator Control:
/*------------------------------------------*/
if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
  normalExpansion();
}
if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) == 1) {
  angledExpansion();
}



  //Refresh at a 10msec rate to prevent data loss
  pros::delay(10);
  }
}
