//*****************************************************************
// Drivetrain.hpp
//-----------------------------------------------------------------
/*This file contains functions that control Drivetrain movements*/
//*****************************************************************

#pragma once // makes sure the file is only included once

//Include all header files
#include "main.h"
//___________________________________________________\\

/*-----------------------------------------------------------------*/
//Chassis Controller builder: PID controller
/*-----------------------------------------------------------------*/
extern std::shared_ptr<ChassisController> turn;
extern std::shared_ptr<ChassisController> skills;
extern std::shared_ptr<ChassisController> drive;

/*-----------------------------------------------------------------*/
//Functions:
/*-----------------------------------------------------------------*/
//Set brake mode to coast
void setDriveCoast();
void setDriveBrake();
//turn function
void turnAngle(int deg);
