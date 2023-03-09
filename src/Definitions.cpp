//*****************************************************************
// Definitions.cpp
//-----------------------------------------------------------------
/*This file contains Robot Configuration.
 Here we define the motors, sensors, actuators, and controllers used.*/
//*****************************************************************

//Include all header files
#include "main.h"
//___________________________________________________\\

namespace def
 {
   /* ----------------------------------------------------------- */
   /* Devices */
   /* ----------------------------------------------------------- */

   /* -------------------------- Motors ------------------------- */
  //Drivetrain
   pros::Motor driveFL(11);
   pros::Motor driveRL(12);
   pros::Motor driveFR(13);
   pros::Motor driveRR(14);
   //Shooter
   pros::MotorGroup Flywheel({-18, 20});
   //Intake&Roller
   pros::Motor Intake(19);
   pros::Motor Roller_Indexer(-10);

   //*------------------------Pneumatics----------------------*//
   //Pneumatics (Expansion)
   //Reservoir: Top
   pros::ADIDigitalOut expansion('B');
   pros::ADIDigitalOut expansionTilt('C');


   //Pneumatics (Indexer)
   //Reservoir: Bottom
   pros::ADIDigitalOut angleChanger('D');

   //*------------------------Sensors----------------------*//
   //Senses robot movements; accerelometer + gyroscope
   pros::Imu inertial(21);
   //Optical Sensor (on Roller Spinner)
   pros::Optical optical(9);
   //Ultrasonic Sensor
   pros::ADIUltrasonic discDetector('G', 'H');
   //*------------------------Controller----------------------*//
   pros::Controller controller(pros::E_CONTROLLER_MASTER);
 }
