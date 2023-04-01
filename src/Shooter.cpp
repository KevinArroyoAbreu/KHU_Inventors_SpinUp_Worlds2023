//*****************************************************************
// Shooter.cpp
//-----------------------------------------------------------------
/*This file contains Shooter control functions.*/
//*****************************************************************

//Include all header files
#include "main.h"
//___________________________________________________\\



//Functions
void flyGetVelocity(){

}
void flySpinToV(int velocity){
 def::Flywheel.moveVelocity(velocity);
}

void flyStop(){
 def::Flywheel.moveVelocity(0);
}


void fwPID(double targetV){

    double kP = 0.3;//0.1
    double kI = 0.04;//0.01
    double errorIntegral = 0;
    
    while(true){
        double velocity = def::Flywheel.getActualVelocity();//0-600rpm

        //Calculate error and adjust motor speed
        double error = targetV - velocity;
        errorIntegral += error;
        double outputSpeed = kP * error + kI * errorIntegral;

        //Update Motor speed
        def::Flywheel.moveVelocity(outputSpeed);

        pros::delay(20);
    }

}
