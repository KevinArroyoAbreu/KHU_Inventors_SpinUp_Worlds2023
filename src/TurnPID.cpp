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
    float turnkP = 0.6;//0.8
    float turnkI = 0.04;//0.2
    float turnkD = 0.04;//0.04 //0.1 is acceptable

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
       // double power = turnkP * error + ( turnkI * integral(error*derivative*t) ) + turnkD( (derivative*error) / derivative*t) ;
        //int outputSpeed = 3*pow(power, 3);// = 3*[power^3]
        int outputSpeed = pow(power, 2);// = 2*[power^2]

        if(heading > desireValue ){ // for left turns
          turnLeft(outputSpeed);//2*pwr --> pwr^2 will give more agressiveness
        }
        else if(heading < desireValue){ // for right turns
          turnRight(outputSpeed);
        }


        pros::screen::print(TEXT_MEDIUM, 5, "Power: %f", power);
        if(power <= 0.5){
          turning = false;
        }
        pros::delay(20);
      }
      driveStop();
    }

void turnInertial(double desireValue){//degrees
      bool turning = true;
      int speed = 200; //rpm of drive
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


        if(heading > desireValue ){ // for left turns
          turnLeft(speed);
        }
        else if(heading < desireValue){ // for right turns
          turnRight(speed);
        }


        pros::screen::print(TEXT_MEDIUM, 5, "Speed: %f", speed);
        pros::delay(20);
      }
      driveStop();
    }
