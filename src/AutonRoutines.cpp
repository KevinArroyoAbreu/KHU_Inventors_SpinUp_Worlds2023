//*****************************************************************
// AutonRoutines.cpp
//-----------------------------------------------------------------
/*This file contains diff. match autonomous routines,
and programming skills*/
//*****************************************************************

//Include all header files
#include "main.h"
//___________________________________________________\\
//--------TURNS----------//
//----Left = (-)---------//
//----Right = (+)--------//
//-----------------------//
//--Remember: absolute---//
//--heading is used------//
//---------------------------------------------------\\
/*-------------------------------------------------------------------------*/
//#0: debuggingRoutineForPathFollowing ->
/*-------------------------------------------------------------------------*/
void pathFollowing(){
//profileController->generatePath({
  //    {0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
  //    {2_ft, 0_ft, 0_deg},
  //   },
   //   "A" // Profile name
   // );
    pcDrive->driveToPoint({24_in, 24_in});

    //profileController->setTarget("A");
    //profileController->waitUntilSettled();
//while(1){
  //pros::screen::print(TEXT_MEDIUM, 3, "Location: %d", pcDrive->getState());
 //}

}

/*-------------------------------------------------------------------------*/
//#1: rollerAuton ->
/*-------------------------------------------------------------------------*/
void rollerAuton(){
  //1)Shoot
  flySpinToV(415);
  pros::delay(2500);//gain rpm
  shoot();
  pros::delay(2000);
  //2)Intake 1 disc
  //3)Turn Roller
  drive->moveDistance(-2_in);
  pros::delay(600);//turn roller (rollerSpinner is on since the shoot)
  rollerStop();
  //4) Approach 2nd shot / intake 2 discs
  flySpinToV(415);//prepare second rpm FW
  drive->moveDistance(2_in);
  intakeV(600);
  turnPID(53);//Right
  drive->moveDistance(36_in);
  //5) Align and shoot
  turn->turnAngle(-63_deg);//Left
  shoot();
  pros::delay(1000);
  rollerStop();
  flySpinToV(410);//prepare third rpm FW
  //6)Intake Discs
  turnPID(50);
  intakeV(600);
  drive->moveDistance(14_in);
  //align with goal
  turn->turnAngle(-74_deg);
  //7)Shoot
  shoot();
  pros::delay(2500);
  rollerStop();
  flyStop();
  intakeStop();
}

/*-------------------------------------------------------------------------*/
//#2: nonRollerAuton ->
/*-------------------------------------------------------------------------*/
void nonRollerAuton(){
  //Intake 1 disc and align with goal
 flySpinToV(433);
 intakeV(600);
 rollerV(-200);
 drive->moveDistance(32_in);
 turnPID(41);
 drive->moveDistance(6_in);
 intakeV(-600);
 shoot();
 rollerV(150);
 pros::delay(4000);
 flyStop();
 rollerStop();
 turnPID(-43);
 drive->moveDistance(-52_in);
 turnPID(0.2);
 drive->moveDistance(-9_in);
 scoreRollerAuton();
 drive->moveDistance(2_in);
 intakeStop();
}

/*-------------------------------------------------------------------------*/
//#3: fullWPAuton ->
/*-------------------------------------------------------------------------*/
void fullWpAuton(){
  //Score Roller 1
  drive->moveDistance(-1_in);
  scoreRollerAuton();
  drive->moveDistance(4_in);
  //Approach shooting distance
  turn->turnAngle(-145_deg);
  flySpinToV(450);
  drive->moveDistance(-140_in);
  //Turn towards roller 2 and turn it
  turn->turnAngle(50.5_deg);
  drive->moveDistance(-6_in);
  scoreRollerAuton();
  drive->moveDistance(2_in);

}

/*-------------------------------------------------------------------------*/
//#4: progSkills --> Programming Skills Routine (USE ONLY 1 PRELOAD!!!!!) to prevent jamming
/*-------------------------------------------------------------------------*/
void  progSkills(){
  //-- Score Roller 1 (2.5 to the right)
  //=========================================================
  flySpinToV(365);//turn on Flywheel
  rollerV(200);
  pcDrive->driveToPoint({-1.2_in, 0_in}, true);//front, side (relative to beginning) // true == bckwd
  opticalRoller();//Score Roller 1
  pcDrive->driveToPoint({3_in, 0_in});
  intakeV(600);//turn on intake
  //-- Intake 1 disc / turn 2nd Roller
  //=========================================================
  pcDrive->driveToPoint({15_in, -12.5_in});
 // pcDrive->turnToAngle(93_deg);//+ right // - left
  rollerV(200);
  pcDrive->driveToPoint({17_in, -22_in}, true);
  opticalRoller();
  pcDrive->driveToPoint({17_in, -18.5_in}); 
  intakeV(600);
  //-- Shot #1 (3 discs)
  //=========================================================
  pcDrive->driveToPoint({40_in, -15.5_in});
  shoot();
  pros::delay(2000);
  //-- Intake (3 discs)
  //=========================================================
  intakeV(600);
  pcDrive->setMaxVelocity(160);
  pcDrive->driveToPoint({30_in, -15.5_in}, true);
  pcDrive->setMaxVelocity(160);
  pcDrive->driveToPoint({67_in, 20_in});//intake discs
  //-- Shot #2 (3 discs)
  //=========================================================
  pcDrive->setMaxVelocity(260);
  pcDrive->turnToAngle(-45_deg);
  shoot();
  pros::delay(2000);
  //-- Intake (disc stack (3))
  //=========================================================
  intakeV(600);
  flySpinToV(380);//new rpm
  pcDrive->driveToPoint({95_in, 46_in});//intake discs (+42, +38)
  //-- Shot #3 (3 discs)
  //=========================================================
  pcDrive->driveToPoint({95_in, 30_in});
  pcDrive->turnToAngle(-80_deg);
  shoot();
  pros::delay(2000);
  //-- Score Roller 3
  //=========================================================
  pcDrive->driveToPoint({95_in, 68_in}, true);
  pcDrive->driveToPoint({110_in, 74_in}, true);
  opticalRoller();
  pcDrive->driveToPoint({107_in, 74_in});
   //-- Score Roller 4 (intake 1 disc)
  //=========================================================

  pros::delay(20000);

  skills->moveDistance(-12_in);
  pros::delay(0);
  rollerStop();
  //------------------------
  skills->moveDistance(8_in);
  turn->turnAngle(-95_deg); 
  flySpinToV(360); //normal shooting
  skills->moveDistance(32_in);
  turn->turnAngle(10_deg);
  shoot();  //Score 2 discs( 1 preload + 1 intaked)
  pros::delay(4000);
  turn->turnAngle(80_deg);
  flyStop();
  //------------------------
  //intake 1 disc on path
  intakeV(600);
  rollerV(-200);
  skills->moveDistance(20_in);
  //Align with discs
  turn->turnAngle(-45_deg);
  //Intake 2 discs
  skills->moveDistance(35_in);
  // Align with blue goal
  turn->turnAngle(-90_deg);
  flySpinToV(380);
  intakeV(-600);//prevent jamming
  pros::delay(500);
  shoot();//shoot 2-3 intaked discs
  pros::delay(2000);
  //--------------------------
  //Approach 2nd roller pair
  skills->moveDistance(-7_in);
  turn->turnAngle(-98_deg);
  flyStop();
  skills->moveDistance(-65_in);
  //align with 3rd roller and score it
  turn->turnAngle(-45_deg);
  rollerV(-200);
  skills->moveDistance(-15_in);
  rollerStop();
  skills->moveDistance(3_in);
  //-------------------------
  intakeV(600);
  rollerV(-200);
  turn->turnAngle(-40_deg);
  skills->moveDistance(22_in);
  turn->turnAngle(125_deg);
  rollerV(-200);  //Score Roller 4
  skills->moveDistance(-13_in);
  pros::delay(0);
  rollerStop();
  //Approach expanding location
  skills->moveDistance(20_in);
  turn->turnAngle(-48_deg);
  //expand
  normalExpansion();

  ////END-OF-ROUTINE////
  //__________________//
  //Expected Results: //
  // --4x Rollers     //
  // -- 6x High Discs  //
  // -- ~26 tiles     //
  //__________________//
  // TOTAL: ~100pts   //
  //////////////////////
}

/*-------------------------------------------------------------------------*/
//#5: progSkillsShort --> short routine (2 rollers, some discs, expansion) about 90pts
/*-------------------------------------------------------------------------*/
void  progSkillsShort(){
  //-- Score Roller 1 (2.5 to the right)
  //=========================================================
  flySpinToV(370);//turn on Flywheel
  rollerV(200);
  pcDrive->moveDistance(-1.2_in);//front, side (relative to beginning) // true == bckwd
  opticalRoller();//Score Roller 1
  pcDrive->moveDistance(4_in);
  intakeV(600);//turn on intake
  //-- Intake 1 disc / turn 2nd Roller
  //=========================================================
  pcDrive->turnToAngle(-40_deg);
  pcDrive->moveDistance(15_in);
  pcDrive->turnToAngle(76_deg);
  rollerV(200);
  pcDrive->moveDistance(-10.5_in);
  opticalRoller();
  pcDrive->moveDistance(6_in);
  intakeV(600);
  //-- Shot #1 (3 discs)
  //=========================================================
  pcDrive->turnToAngle(8_deg);
  pcDrive->moveDistance(24_in);
  shootSlow();
  pros::delay(3000);
  pcDrive->turnToAngle(-14_deg);
  //-- Accomodate for expansion
  //=========================================================
  pcDrive->moveDistance(-26_in);
  pcDrive->setMaxVelocity(100);
  pcDrive->turnToAngle(40_deg);
  //-- Expand
  //=========================================================
  normalExpansion();

  ////END-OF-ROUTINE/////////
  //_______________________//
  //Expected Results:      //
  // --------------------- //
  // --2x Rollers          //
  // -- 3x High Discs      // 
  // -- ~26-28 tiles       //
  //_______________________//
  // TOTAL: ~113 - 119 pts //
  ///////////////////////////
}




/*-------------------------------------------------------------------------*/
//#6: progSkillsPID --> Skills with PID turns
/*-------------------------------------------------------------------------*/
void  progSkillsPID(){
  rollerV(-200);//Score Roller 1
  skills->moveDistance(-3_in);
  pros::delay(0);
  rollerStop();
  skills->moveDistance(4_in);
  //-------------------------
  intakeV(600);
  rollerV(-200);
  turnPID(-40);
  skills->moveDistance(20_in);
  turnPID(88);
  rollerV(-200);  //Score Roller 2
  skills->moveDistance(-11.5_in);
  pros::delay(0);
  rollerStop();
  //------------------------
  skills->moveDistance(8_in);
  turnPID(0);
  flySpinToV(360); //normal shooting
  skills->moveDistance(32_in);
  turn->turnAngle(13_deg);//use no PID for small turns
  intakeV(-600);//prevent Jamming
  shoot();  //Score 2 discs( 1 preload + 1 intaked)
  pros::delay(4000);
  turnPID(90);
  flyStop();
  //------------------------
  //intake 1 disc on path
  intakeV(600);
  rollerV(-200);
  skills->moveDistance(20_in);
  //Align with discs
  turnPID(45);
  //Intake 2 discs
  skills->moveDistance(35_in);
  flySpinToV(372);//Shot #2
  // Align with blue goal
  turnPID(-39);
  intakeV(-600);//prevent jamming
  pros::delay(500);
  intakeV(-600);//prevent Jamming
  shoot();//shoot 2-3 intaked discs
  pros::delay(2000);
  //--------------------------
  //Approach 2nd roller pair
  skills->moveDistance(-7_in);
  turnPID(-126);
  flyStop();
  intakeStop();
  skills->moveDistance(-65_in);
  //align with 3rd roller and score it
  turnPID(-180);
  rollerV(-200); //Score Roller 3
  skills->moveDistance(-13_in);
  rollerStop();
  skills->moveDistance(4_in);
  //-------------------------
  rollerV(-200);
  turn->turnAngle(-40_deg);// opposite direction!
  skills->moveDistance(23_in);
  turn->turnAngle(130_deg);//opposite direction!
  rollerV(-200);  //Score Roller 4
  skills->moveDistance(-9_in);
  pros::delay(0);
  rollerStop();
  //Approach expanding location
  skills->moveDistance(22_in);
  turn->turnAngle(-45_deg);
  skills->moveDistance(-12_in);
  //expand
  normalExpansion();

  ////END-OF-ROUTINE////
  //__________________//
  //Expected Results: //
  // --4x Rollers     //
  // -- 6x High Discs  //
  // -- ~26 tiles     //
  //__________________//
  // TOTAL: ~100pts   //
  //////////////////////
}
