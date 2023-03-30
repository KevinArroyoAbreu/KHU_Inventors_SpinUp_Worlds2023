//*****************************************************************
// Intake&Roller.cpp
//-----------------------------------------------------------------
/*This file contains Intake&Roller control functions.*/
//*****************************************************************

//Include all header files
#include "main.h"
//___________________________________________________\\

//Functions
void intakeV(int velocity){
 def::Intake.moveVelocity(velocity);
 def::Roller_Indexer.moveVelocity(200);
}
void intakeStop(){
  def::Intake.moveVelocity(0);
}
void shoot(){
 def::Roller_Indexer.moveVelocity(-180);
}
void shootatV(int minV, int maxV){
int i = 0;
while(1){
  int time = 0;
  if(def::Flywheel.getActualVelocity() >= minV && def::Flywheel.getActualVelocity() <= maxV){
  pros::delay(0);  
  shoot1by1(1);
  i ++;
  pros::screen::print(TEXT_LARGE, 4, "shootatV i: %f", i);
  }
  else {
    rollerStop();
  }
  if(i == 3 || time == 3){
    break;
  }
  pros::delay(10);
  time == 0.01;
}
}
void shootSlow(){
 def::Roller_Indexer.moveVelocity(-110);
}
void shoot1(int delay){
  int i = 0;
  while(def::discDetector.get_value() >= 40){ 
   def::Roller_Indexer.moveVelocity(-200);
   pros::delay(20);
   if(def::discDetector.get_value() <= 40 || i == 100){
    break;
   }
   i++;
  }
  rollerStop();
  pros::delay(delay);
}
void shoot1by1(int discQuantity){
  int delay = 100;
  if(discQuantity == 1){
    //One shot
    shoot1(delay);
  }
  else if(discQuantity == 2){
    //First shot
    shoot1(delay);
    //Second shot
    shoot();
    pros::delay(800);
    rollerStop();
  }
  else if(discQuantity == 3){
    //First shot
    shoot1(delay);
    //Second shot
    shoot1(delay);
    //Third shot
    shoot();
    pros::delay(800);
    rollerStop();
  }

}
void angleDown(){
 def::angleChanger.set_value(false);
}
void angleUp(){
 def::angleChanger.set_value(true);
}
void scoreRollerAuton(){
 rollerV(-200);
 pros::delay(200);//400
 rollerStop();
}
void rollerStop(){
  def::Roller_Indexer.moveVelocity(0);
}
void rollerV(int velocity){
  def::Roller_Indexer.moveVelocity(velocity);
}
void opticalRoller(){
  //turn on optical sensor led
  def::optical.set_led_pwm(60);
  while(def::optical.get_hue() < 100 || def::optical.get_hue() > 290 ){
    rollerV(200);
    pros::delay(15);
  }
  pros::delay(0);
  rollerStop();
  def::optical.set_led_pwm(0);
}
