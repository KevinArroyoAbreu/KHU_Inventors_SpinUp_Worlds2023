//*****************************************************************
// Expansion.cpp
//-----------------------------------------------------------------
/*This file contains Expansion Mechanism control functions.*/
//*****************************************************************

//Include all header files
#include "main.h"
//___________________________________________________\\

//Functions
void normalExpansion(){
  def::expansion.set_value(true);
}
void angledExpansion(){
  def::expansionTilt.set_value(true);
  pros::delay(300);
  def::expansion.set_value(true);
  pros::delay(300);
  def::expansionTilt.set_value(false);
}
