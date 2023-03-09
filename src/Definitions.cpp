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
   Motor driveFL(11);
   Motor driveRL(12);
   Motor driveFR(13);
   Motor driveRR(14);
   //Shooter
   MotorGroup Flywheel({-18, 20});
   //Intake&Roller
   Motor Intake(19);
   Motor Roller_Indexer(-10);

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
