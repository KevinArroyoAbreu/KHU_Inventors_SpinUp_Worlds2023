//*******************************************************************************
// autonSelection.h
//-------------------------------------------------------------------------------
/*This file contains code used for selecting autonomous routines from the brain*/
//*******************************************************************************

#pragma once
//#include "main.h"
#include <string>

//selector configuration
#define HUE 360
#define DEFAULT 1
#define AUTONS "default", "extra", "Full Wp"

namespace selector{

extern int auton;
const char *b[] = {AUTONS, ""};
void init(int hue = HUE, int default_auton = DEFAULT, const char **autons = b);

}
