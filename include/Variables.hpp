//*****************************************************************
// Variables.hpp
//-----------------------------------------------------------------
/*This file contains global variables*/
//*****************************************************************

#pragma once // makes sure the file is only included once

//Include all header files
#include "main.h"
//_________________________________________________________________


extern int driveMult;
extern int turnMult;

//PID
// distance controller gains
extern float dkP;
extern float dkI;
extern float dkD;
// turn controller gains
extern float tkP;
extern float tkI;
extern float tkD;
// angle controller gains
extern float akP;
extern float akI;
extern float akD;
