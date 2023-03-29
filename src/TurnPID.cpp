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

void turnInertial(double desireValue, bool direction = false){//degrees

      //true == left / false == right

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
        
        double power = 0.5*abs(error);
        int outputSpeed = 3*power;//6 

        if(heading > desireValue ){ // for left turns
          turnLeft(outputSpeed);
        }
        else if(heading < desireValue){ // for right turns
          turnRight(outputSpeed);
        }


        pros::screen::print(TEXT_MEDIUM, 5, "Power: %f", power);
        pros::screen::print(TEXT_MEDIUM, 5, "Output Speed: %f", outputSpeed);

        if(power <= 0.5){
          turning = false;
        }
        pros::delay(20);
      }
      driveStop();
    }


    //------------------------------------------------------------------------------
    void rSideTurn(int degrees, bool direction){
      leftDriveBrake();//hold
      double distanceToMove = 5*(3.14*degrees/180);
      double ticksToMove = (300*1.6*distanceToMove) / 8.2958; //1 rev = 1.625 / 1 rev = 300(1.6) ticks (3.25in wheels)

    def::driveFR.tarePosition();
    def::driveRR.tarePosition();

  if(direction == false){//left
   while( def::driveRR.getPosition() <= ticksToMove){
     def::driveFR.moveVelocity(-180);
     def::driveRR.moveVelocity(180);
    }
   }  
   else if(direction == true){//right
    while( def::driveRR.getPosition() >= -ticksToMove){
     def::driveFR.moveVelocity(180);
     def::driveRR.moveVelocity(-180);
    }
   }
   
      pros::c::motor_set_brake_mode(13, MOTOR_BRAKE_HOLD);
      pros::c::motor_set_brake_mode(14, MOTOR_BRAKE_HOLD);
      def::driveFR.moveVelocity(0);
      def::driveRR.moveVelocity(0);
      
    }