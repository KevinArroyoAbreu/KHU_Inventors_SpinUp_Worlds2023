//*****************************************************************
// Drivetrain.cpp
//-----------------------------------------------------------------
/*This file contains functions that control Drivetrain movements*/
//*****************************************************************
#include "main.h"

///////////////////////////////
/*-----------------------------------------------------------------*/
//Chassis Controller builders for Pure Pursuit Controllers
/*-----------------------------------------------------------------*/
//Chassis Controller
std::shared_ptr<OdomChassisController> rightDrive =
ChassisControllerBuilder()
  .withMotors({5,6},{-13,14} )//5 and 6 are null (for right drive turns)
  // Blue gearset, 3.25" inch wheel diameter, 10 inch wheel track; 36/60 transmission
  .withDimensions({AbstractMotor::gearset::blue, (60 / 36)}, {{3.25_in/2, 10_in}, imev5BlueTPR})
  .withSensors(IntegratedEncoder(13), IntegratedEncoder(14))
 /* .withGains(
    {dkP, dkI, dkD}, // distance controller gains
    {tkP, tkI, tkD}, // turn controller gains
    {akP, akI, akD}
  )*/
  .withMaxVelocity(260)
  .withOdometry()
  .buildOdometry();


//half turn -- Chassis Controller
std::shared_ptr<OdomChassisController> pcDrive =
ChassisControllerBuilder()
  .withMotors({11,-12},{-13,14} )
  // Blue gearset, 3.25" inch wheel diameter, 10 inch wheel track; 36/60 transmission
  .withDimensions({AbstractMotor::gearset::blue, (60 / 36)}, {{3.25_in/2, 10_in}, imev5BlueTPR})
 /* .withGains(
    {dkP, dkI, dkD}, // distance controller gains
    {tkP, tkI, tkD}, // turn controller gains
    {akP, akI, akD}
  )*/
  .withMaxVelocity(260)
  .withOdometry()
  .buildOdometry();



//Async Motion Profile Controller
std::shared_ptr<AsyncMotionProfileController> profileController =
  AsyncMotionProfileControllerBuilder()
      .withLimits({
        1.56, // Maximum linear velocity of the Chassis in m/s
        3.41, // Maximum linear acceleration of the Chassis in m/s/s
        6.82 // Maximum linear jerk of the Chassis in m/s/s/s (2x accel.) [adjust for aggressive/smooth turns]
      })
      .withOutput(pcDrive)
      .buildMotionProfileController();


/*-----------------------------------------------------------------*/
//Chassis Controller builder: PID controller
/*-----------------------------------------------------------------*/
std::shared_ptr<ChassisController> turn =
ChassisControllerBuilder()
  .withMotors({11,-12},{-13,14} )
  // Blue gearset, 3.25" inch wheel diameter, 10 inch wheel track; 36/60 transmission
  .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{3.25_in, 10_in}, imev5BlueTPR})
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
    // Blue gearset, 3.25" inch wheel diameter, 10 inch wheel track; 36/60 transmission
    .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{3.25_in, 10_in}, imev5BlueTPR})
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
    // Blue gearset, 3.25" inch wheel diameter, 10 inch wheel track; 36/60 transmission
    .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{3.25_in, 10_in}, imev5BlueTPR})
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
  pros::c::motor_set_brake_mode(11, MOTOR_BRAKE_HOLD);
  pros::c::motor_set_brake_mode(12, MOTOR_BRAKE_HOLD);
  pros::c::motor_set_brake_mode(13, MOTOR_BRAKE_HOLD);
  pros::c::motor_set_brake_mode(14, MOTOR_BRAKE_HOLD);
}
void leftDriveBrake(){
  pros::c::motor_set_brake_mode(11, MOTOR_BRAKE_HOLD);
  pros::c::motor_set_brake_mode(12, MOTOR_BRAKE_HOLD);
}
void rightDriveBrake(){
  pros::c::motor_set_brake_mode(13, MOTOR_BRAKE_HOLD);
  pros::c::motor_set_brake_mode(14, MOTOR_BRAKE_HOLD);
}

//drive bckwd until roller reached (Ultrasonic sensor)
 void driveToRoller(){
  int speed = -60;//rpm bckwds

  double target = 133;

  while(def::rearUltrasonic.get_value() >= target){
     //LEFT
    pros::c::motor_move(11,  speed);
    pros::c::motor_move(12, -speed);
     //RIGHT
    pros::c::motor_move(13, -speed);
    pros::c::motor_move(14,  speed);
    pros::screen::print(TEXT_LARGE, 3, "rearUltrasonic: %d", def::rearUltrasonic.get_value());
    pros::delay(20);
  }
  driveStop();

   }
