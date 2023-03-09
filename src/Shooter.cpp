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
