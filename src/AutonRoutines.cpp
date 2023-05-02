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
  flySpinToV(425);//400//420
 // pros::delay(3000);
 // shootatV(420, 425);
 // pros::delay(20000);
 //--------------------------
 intakeV(600);
 rSideTurn(100, false);//60
 //pcDrive->moveDistance(2_in);
 pros::delay(100);
 rSideTurn(74, true);//to the right (45)//53/78//72
 pros::delay(100);//500
 shootatV(422, 427);
 //pros::delay(800);//1500
 //shootatV(399, 410);//avg. for shooting at correct velocity//399,402
 pcDrive->moveDistance(-2.5_in);
 scoreRollerAuton();
 pcDrive->moveDistance(3_in);
 //continue routine
  flySpinToV(430);//prepare second rpm FW
  intakeV(600);
  pcDrive->turnAngle(43_deg);//Right (43)
  pcDrive->setMaxVelocity(300);//200
  pcDrive->moveDistance(22_in);//36
  pros::delay(100);
  pcDrive->setMaxVelocity(160);
  pcDrive->moveDistance(20_in);
  pros::delay(500);
  intakeV(0);
  rollerV(200);
  pcDrive->turnAngle(-76_deg);//70
  //7)Shoot
  shootSlow();
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
 flySpinToV(394);
 intakeV(600);
 drive->moveDistance(20_in);
 pcDrive->turnAngle(22_deg);
 pros::delay(600);
 shootSlow();
 pros::delay(1500);
 rollerStop();
 flySpinToV(401);
 //pcDrive->turnAngle(15_deg);
 intakeV(600);
 //-//pcDrive->setMaxVelocity(160);
 //-//pcDrive->moveDistance(6_in);
 //-//pcDrive->moveDistance(-8_in);
 //--
 pcDrive->turnAngle(-62_deg);
 pcDrive->moveDistance(23_in);
 pcDrive->turnAngle(69_deg);
 pros::delay(300);
 //--
 //--//lSideTurn(20, false);
 shootSlow();
 pros::delay(1500);//500
 pcDrive->turnAngle(-76_deg);//-62//70
 pcDrive->setMaxVelocity(380);
 pcDrive->moveDistance(-54_in);//-32
 rollerV(-200);
 //rSideTurn(70, true);//70
 //driveToRoller();
 pros::delay(200);
 rollerStop();
 flyStop();
 intakeStop();
}


//extra nonRoller
void nonRollerExtraAuton(){
  //Intake 1 disc and align with goal
 flySpinToV(422);//420
 rollerV(-200);
 pcDrive->moveDistance(-10_in);
 rSideTurn(100, true);
 rollerStop();
 rSideTurn(20, false);
 //turnPID(55, 1.5);
 //pcDrive->turnAngle(15_deg);
 intakeV(600);
 //-//pcDrive->setMaxVelocity(160);
 //-//pcDrive->moveDistance(6_in);
 //-//pcDrive->moveDistance(-8_in);
 //--
 pcDrive->moveDistance(23_in);
 pcDrive->turnAngle(56_deg); //60
 pros::delay(300);
 //--
 //--//lSideTurn(20, false);
 shootSlow();
 pros::delay(1500);//500
 //intake 1 (auton line)
 intakeV(600);
 flySpinToV(404);//410
 pcDrive->moveDistance(6_in);
 pcDrive->moveDistance(-6_in);
 //intake 2 more and shoot
 pcDrive->turnAngle(-50_deg);//-62//70//(54)
 pcDrive->setMaxVelocity(300);
 pcDrive->moveDistance(30_in);//-32
 //accomodate and shoot
 pcDrive->turnAngle(72.6_deg);//78/74
 shootSlow();
 pros::delay(1800);
 rollerStop();
 flyStop();
 intakeStop();
}


/*-------------------------------------------------------------------------*/
//#3: fullWPAuton ->
/*-------------------------------------------------------------------------*/
void fullWpAuton(){
  //turn on flywheel
  flySpinToV(406);
  //turn roller (on roller side)
  rollerV(-100);
  pcDrive->moveDistance(-1.2_in);//front, side (relative to beginning) // true == bckwd
  intakeV(600);//turn on intake
  pcDrive->moveDistance(3_in);
  //intake 3 disc stack
  intakeV(600);
  pcDrive->turnAngle(41_deg);//Right (41)//38
  //turnPID(45, 1.5);
  pcDrive->setMaxVelocity(400);//200
  pcDrive->moveDistance(48_in);//42
   // pros::delay(100);
// pcDrive->setMaxVelocity(160);
  //pcDrive->moveDistance(20_in);
  pros::delay(500);
  intakeV(0);
  rollerV(200);
  //turnPID(-25, 1.5);//30
  pcDrive->turnAngle(-78_deg);//-68
  //shoot 3 discs
  shootSlow();
  pros::delay(1500);
  flySpinToV(450);//new rpm FW
  //intake 3 disc row
  turnPID(47, 1.5);//50
  //pcDrive->turnAngle(65_deg);//63
  intakeV(600);
  pcDrive->setMaxVelocity(400);
  pcDrive->moveDistance(62_in);//68
  //turn roller
  pcDrive->turnAngle(-124_deg);
  rollerV(-100);
  driveToRoller();
  pros::delay(200);
  rollerStop();
  //shoot 3 discs
  //lSideTurn(25, true);
  //shootSlow();
  //pros::delay(2000);
  rollerStop();
  flyStop();
  intakeStop();

}

/*-------------------------------------------------------------------------*/
//#4: progSkills --> Programming Skills Routine 
/*-------------------------------------------------------------------------*/
void  progSkills(){
  angleUp();
    //-- Score Roller 1 (2.5 to the right)
  //=========================================================
  flySpinToV(365);//turn on Flywheel
  rollerV(200);
  pcDrive->moveDistance(-1.2_in);//front, side (relative to beginning) // true == bckwd
  opticalRoller();//Score Roller 1
  intakeV(600);//turn on intake
  //-- Intake 1 disc / turn 2nd Roller
  //=========================================================
  rSideTurn(70, false);
  pros::delay(200);
  pcDrive->moveDistance(14_in);
  //pcDrive->turnToAngle(76_deg);
  turnPID(90, 1.5);//1.5 second timer
  rollerV(200);
  pcDrive->setMaxVelocity(200);
  pcDrive->moveDistance(-12.6_in);//-13
  opticalRoller();
  pcDrive->moveDistance(8_in);
  intakeV(600);
  //-- Shot #1 (3 discs)
  //=========================================================
  turnPID(10, 1.5);
  pcDrive->setMaxVelocity(220);
  pcDrive->moveDistance(26_in);
  shootSlow();
  pros::delay(3000);
  flySpinToV(375);
  //-- Intake #2
  //=========================================================
  pcDrive->moveDistance(-14_in);
  turnPID(54, 1.5);
  intakeV(600);
  pcDrive->moveDistance(50_in);
  // -- Shoot#2
  //=========================================================
  turnPID(-35, 1.5);
  shoot();
  pros::delay(3000);
  flySpinToV(380);
  // -- Stack(Intake)#1
  //=========================================================
  turnPID(51, 1.5);
  intakeV(600);
  pcDrive->setMaxVelocity(300);
  pcDrive->moveDistance(20_in);
  pcDrive->setMaxVelocity(160);
  pcDrive->moveDistance(25_in);
  // -- Shoot#3
  //=========================================================
  turnPID(-80, 1.5);
  pros::delay(600);
  shootSlow();
  pros::delay(3000);
  //--REPEAT on other side(Mirrored field)
  // -- Roller#3
  //=========================================================
  rollerV(200);
  pcDrive->setMaxVelocity(220);
  pcDrive->moveDistance(-5.5_in);
  turnPID(-170, 2);
  driveToRoller();
  pros::delay(400);
  opticalRoller();//Score Roller 3
  pros::delay(300);
  //-- Intake 1 disc / turn 4th Roller
  //=========================================================
  rSideTurn(70, false);
  pros::delay(200);
  pcDrive->moveDistance(13_in);
  pcDrive->turnAngle(98_deg);
  rollerV(200);
  pcDrive->setMaxVelocity(200);
  driveToRoller();
  opticalRoller();
  pcDrive->moveDistance(12_in);
  intakeV(600);
  pcDrive->turnAngle(-45_deg);

  //---------------
  
 /* //-- Shot #4 (1 disc)
  //=========================================================
  turnPID(-170, 1.5);
  pcDrive->setMaxVelocity(220);
  pcDrive->moveDistance(26_in);
  shootSlow();
  pros::delay(1500);
  //-- Intake #2 repeat
  //=========================================================
  pcDrive->moveDistance(-17_in);
  turnPID(-123, 1.5);
  intakeV(600);
  pcDrive->moveDistance(50_in);
  // -- Shoot#5 (3 discs)
  //=========================================================
  pcDrive->turnAngle(-78_deg);
  shoot();
  pros::delay(3000);
  // -- Expand
  //=========================================================
  turnPID(68, 1.5);
  pcDrive->setMaxVelocity(350);
  pcDrive->moveDistance(-58_in);
  pcDrive->turnAngle(-13_deg);  */
  normalExpansion();
  intakeStop();
  rollerStop();
  flyStop();
  /////END-OF-ROUTINE/////
  //____________________//
  //Expected Results:   //
  // --4x Rollers       //
  // --16x High Discs   //
  // -- ~26-28 tiles    //
  //____________________//
  // TOTAL: ~195pts     //
  ////////////////////////
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
  pcDrive->turnToAngle(6.5_deg);
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
 // turnPID(-40);
  skills->moveDistance(20_in);
  //turnPID(88);
  rollerV(-200);  //Score Roller 2
  skills->moveDistance(-11.5_in);
  pros::delay(0);
  rollerStop();
  //------------------------
  skills->moveDistance(8_in);
 // turnPID(0);
  flySpinToV(360); //normal shooting
  skills->moveDistance(32_in);
  turn->turnAngle(13_deg);//use no PID for small turns
  intakeV(-600);//prevent Jamming
  shoot();  //Score 2 discs( 1 preload + 1 intaked)
  pros::delay(4000);
  //turnPID(90);
  flyStop();
  //------------------------
  //intake 1 disc on path
  intakeV(600);
  rollerV(-200);
  skills->moveDistance(20_in);
  //Align with discs
 // turnPID(45);
  //Intake 2 discs
  skills->moveDistance(35_in);
  flySpinToV(372);//Shot #2
  // Align with blue goal
 // turnPID(-39);
  intakeV(-600);//prevent jamming
  pros::delay(500);
  intakeV(-600);//prevent Jamming
  shoot();//shoot 2-3 intaked discs
  pros::delay(2000);
  //--------------------------
  //Approach 2nd roller pair
  skills->moveDistance(-7_in);
 // turnPID(-126);
  flyStop();
  intakeStop();
  skills->moveDistance(-65_in);
  //align with 3rd roller and score it
  //turnPID(-180);
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
