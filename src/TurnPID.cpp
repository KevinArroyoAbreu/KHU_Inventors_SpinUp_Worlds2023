//*****************************************************************
// TurnPID.hpp
//-----------------------------------------------------------------
/*This file contains functions that control
Drivetrain turns with PID and inertial sensor*/
//*****************************************************************
#include "main.h"

///////////////////////////////
    void turnRight(int speed)
    {
      //LEFT
     pros::c::motor_move(11, speed);
     pros::c::motor_move(12, - speed);
      //RIGHT
     pros::c::motor_move(13,   speed);
     pros::c::motor_move(14, - speed);

   }
   void turnLeft(int speed)
   {
     //LEFT
    pros::c::motor_move(11,-speed);
    pros::c::motor_move(12, speed);
     //RIGHT
    pros::c::motor_move(13, -speed);
    pros::c::motor_move(14,  speed);

   }
    void driveStop()
    {
      //LEFT
     pros::c::motor_move(11, MOTOR_BRAKE_BRAKE);
     pros::c::motor_move(12, MOTOR_BRAKE_BRAKE);
      //RIGHT
     pros::c::motor_move(13, MOTOR_BRAKE_BRAKE);
     pros::c::motor_move(14, MOTOR_BRAKE_BRAKE);
    }

    // turn controller gains
    float turnkP = 0.8;
    float turnkI = 0.2;
    float turnkD = 0.04;

    double error;
    int prevError = 0;
    int derivative;
    int totalError = 0;
    int turnDifference;


    void turnPID(double desireValue){//degrees
      bool turning = true;

      while(turning){

        double  heading;

        if(180 >= def::inertial.get_heading() & def::inertial.get_heading() >= 0){
          heading = def::inertial.get_heading();
        }
        else if( 360 >= def::inertial.get_heading() & def::inertial.get_heading() >= 180){
          heading = def::inertial.get_heading() - 360;
        }

        pros::screen::print(TEXT_MEDIUM, 3, "Heading: %f", heading);
        totalError = error;

        //Potential

          error = abs( desireValue - heading );


        pros::screen::print(TEXT_MEDIUM, 4, "Error: %f", error);
        //Derivative
        derivative = error - prevError;

        //Integral
        totalError += error;

        double power = error * turnkP + derivative * turnkD + totalError * turnkI;

        if(heading > desireValue ){ // for left turns
          turnLeft(2*power);
        }
        else if(heading < desireValue){ // for right turns
          turnRight(2*power);
        }


        pros::screen::print(TEXT_MEDIUM, 5, "Power: %f", power);
        if(power <= 10){
          turning = false;
        }
        pros::delay(20);
      }
      driveStop();
    }




void turnInertialL (int deg, int speed){
  setDriveBrake();
   while(def::inertial.get_heading() >= ( (360-deg) + 20 ) ){//20 degree threshold
     turnLeft(speed);
     pros::screen::print(TEXT_LARGE, 3, "Inertial: %f", def::inertial.get_heading());
     pros::delay(20);
   }
   driveStop();
 }
 void turnInertialR (int deg, int speed){
   setDriveBrake();
    while(def::inertial.get_heading() <= (deg - 10) ){//10 degree threshold
      turnRight(speed);
      pros::screen::print(TEXT_LARGE, 3, "Inertial: %f", def::inertial.get_heading());
      pros::delay(20);
    }
    driveStop();
  }
