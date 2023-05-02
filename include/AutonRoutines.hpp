//*****************************************************************
// AutonRoutines.hpp
//-----------------------------------------------------------------
/*This file contains diff. match autonomous routines,
and programming skills*/
//*****************************************************************

#pragma once // makes sure the file is only included once

//Include all header files
#include "main.h"
//___________________________________________________\\
/*-------------------------------------------------------------------------*/
//#0: debuggingRoutineForPathFollowing ->
/*-------------------------------------------------------------------------*/
void pathFollowing();
/*-------------------------------------------------------------------------*/
//#1: rollerAuton ->
/*-------------------------------------------------------------------------*/
void rollerAuton();

/*-------------------------------------------------------------------------*/
//#2: nonRollerAuton ->
/*-------------------------------------------------------------------------*/
void nonRollerAuton();

//extra nonRoller auton
void nonRollerExtraAuton();
/*-------------------------------------------------------------------------*/
//#3: fullWPAuton ->
/*-------------------------------------------------------------------------*/
void fullWpAuton();

/*-------------------------------------------------------------------------*/
//#4: progSkills --> Programming Skills Routine
/*-------------------------------------------------------------------------*/
void  progSkills();

/*-------------------------------------------------------------------------*/
//#5: progSkillsShort --> short routine (2 rollers, some discs, expansion) about 90pts
/*-------------------------------------------------------------------------*/
void  progSkillsShort();

/*-------------------------------------------------------------------------*/
//#6: progSkillsPID --> Skills with PID turns
/*-------------------------------------------------------------------------*/
void  progSkillsPID();
