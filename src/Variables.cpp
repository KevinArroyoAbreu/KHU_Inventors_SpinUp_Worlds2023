//*****************************************************************
// Variables.cpp
//-----------------------------------------------------------------
/*This file contains global variables*/
//*****************************************************************

//Include all header files
#include "main.h"
//_________________________________________________________________

//PID
// distance controller gains
float dkP = 0.0025;
float dkI = 0.0000;
float dkD = 0.00004;
// turn controller gains
float tkP = 0.0;
float tkI = 0.0;
float tkD = 0.0;
/*
float tkP = 0.0035;
float tkI = 0.00;
float tkD = 0.00009;
*/
// angle controller gains
float akP = 0.00;
float akI = 0.00;
float akD = 0.00;
