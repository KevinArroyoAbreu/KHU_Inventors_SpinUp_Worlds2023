//*****************************************************************
// Intake&Roller.hpp
//-----------------------------------------------------------------
/*This file contains Intake&Roller control functions.*/
//*****************************************************************

#pragma once // makes sure the file is only included once

//Include all header files
#include "main.h"
//___________________________________________________\\

//Functions
void intakeV(int velocity);
void intakeStop();
void shoot();
void shoot1(int delay);
void shoot1by1(int discQuantity);
void angleDown();
void angleUp();
void scoreRollerAuton();
void rollerStop();
void rollerV(int velocity);
void stopWColor();
