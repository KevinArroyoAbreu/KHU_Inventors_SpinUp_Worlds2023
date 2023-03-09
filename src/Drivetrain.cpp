//*****************************************************************
// Drivetrain.cpp
//-----------------------------------------------------------------
/*This file contains functions that control Drivetrain movements*/
//*****************************************************************
#include "main.h"

///////////////////////////////


/*-----------------------------------------------------------------*/
//Chassis Controller builder: PID controller
/*-----------------------------------------------------------------*/
std::shared_ptr<ChassisController> turn =
ChassisControllerBuilder()
  .withMotors({11,-12},{-13,14} )
  // Blue gearset, 2.75" inch wheel diameter,  11 inch wheel track; 36/60 transmission
  .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{3.25_in, 11_in}, imev5BlueTPR})
  //.withGains(
  //  {dkP, dkI, dkD}, // distance controller gains
  //  {tkP, tkI, tkD}, // turn controller gains
  //  {akP, akI, akD}
//  )
  .withMaxVelocity(120)
  .withOdometry()
  .buildOdometry();

  std::shared_ptr<ChassisController> skills =
  ChassisControllerBuilder()
    .withMotors({11,-12},{-13,14} )
    // Blue gearset, 2.75" inch wheel diameter,  11 inch wheel track; 36/60 transmission
    .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{3.25_in, 11_in}, imev5BlueTPR})
  /*  .withGains(
      {dkP, dkI, dkD}, // distance controller gains
      {tkP, tkI, tkD}, // turn controller gains
      {akP, akI, akD}
    )*/
    .withMaxVelocity(200)
    .withOdometry()
    .buildOdometry();


  std::shared_ptr<ChassisController> drive =
  ChassisControllerBuilder()
    .withMotors({11,-12},{-13,14} )
    // Blue gearset, 2.75" inch wheel diameter,  11 inch wheel track; 36/60 transmission
    .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{3.25_in, 11_in}, imev5BlueTPR})
  /*  .withGains(
      {dkP, dkI, dkD}, // distance controller gains
      {tkP, tkI, tkD}, // turn controller gains
      {akP, akI, akD}
    ) */
    .withMaxVelocity(250)
    .withOdometry()
    .buildOdometry();

/*-----------------------------------------------------------------*/
//Functions:
/*-----------------------------------------------------------------*/
//Set brake mode to coast
void setDriveCoast(){
  pros::c::motor_set_brake_mode(11, MOTOR_BRAKE_COAST);
  pros::c::motor_set_brake_mode(12, MOTOR_BRAKE_COAST);
  pros::c::motor_set_brake_mode(13, MOTOR_BRAKE_COAST);
  pros::c::motor_set_brake_mode(14, MOTOR_BRAKE_COAST);
}
void setDriveBrake(){
  pros::c::motor_set_brake_mode(11, MOTOR_BRAKE_BRAKE);
  pros::c::motor_set_brake_mode(12, MOTOR_BRAKE_BRAKE);
  pros::c::motor_set_brake_mode(13, MOTOR_BRAKE_BRAKE);
  pros::c::motor_set_brake_mode(14, MOTOR_BRAKE_BRAKE);
}
//turn function
/*void turnAngle(int deg){
  int v = 200; // rpm velocity of turns

  float distance = 264*(3.14159)*(deg/360);
  float revs = 1.67*(distance/69.85);
  int ticks = 300*(revs);

  pros::c::motor_move_relative(11, ticks, v);
  pros::c::motor_move_relative(12, -ticks, v);
  pros::c::motor_move_relative(13, ticks, v);
  pros::c::motor_move_relative(14, -ticks, v);

}*/
