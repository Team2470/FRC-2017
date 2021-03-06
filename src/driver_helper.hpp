//*****************************************************************************
// Filename:            driver_helper.hpp
//
// Revision Record:
//   Author             Date       Description
//   ------------------ ---------- --------------------------------------------
//   Chris Struck       Jan. 2018  Initial design.
//
// Description:
//    This class operates a SpeedController group using Differential Drive.
//    The class has the ability to drive using tele-operated Arcade Drive, 
//        autonomous arcade drive, and should be updated for other versions of 
//        as needed (tank, H, etc.).
// 
// Dependencies:
//    None
//*****************************************************************************

#ifndef DRIVER_HELPER_HPP
#define DRIVER_HELPER_HPP

/******************************************************************************
 * Include Files
 *****************************************************************************/
// FIRST Includes
#include <Drive/DifferentialDrive.h>
#include <Joystick.h>
#include <Spark.h>

/******************************************************************************
 * Constants
 *****************************************************************************/

/******************************************************************************
 * Types
 *****************************************************************************/

/******************************************************************************
 * CLASS      : BjorgDrive
 *
 * DESCRIPTION: This class creates a DifferentialDrive Object
 *
 * RETURNS    : None
 *****************************************************************************/
class BjorgDrive 
{
public:
	
    /**************************************************************************
     * Variables
     *************************************************************************/
	int moveCtrl 	 = 0;
	int rotateCtrl 	 = 0;
	int rtTurn		 = 0;
	int lftTurn		 = 0;
	int fwdDrive	 = 0;
	int bckDrive	 = 0;
	int joystickInt  = 0;
	int reverseDrive = -1;

	bool rotateEnable = true;
	bool sqrInputs	 = false;
	bool multiRotate = false;
	bool multiMove   = false;
	float motorMultiplier = 1.0;
	float rotateMult = 0.5;
	
    /**************************************************************************
     * FUNCTION   : BjorgDrive
     *
     * DESCRIPTION: Construct class BjorgDrive, set the motors to be used for 
     *              driving with <m_leftMotor> and <m_rightMotor> and the 
     *              Joystick used to drive <Joystick>.
     *
     * RETURNS    : A DifferentialDrive object
     *************************************************************************/	
	BjorgDrive(frc::Spark *m_leftMotor, frc::Spark *m_rightMotor, 
        frc::Joystick *controller1, frc::Joystick *controller2);

    /**************************************************************************
     * FUNCTION   : arcadeDrive
     *
     * DESCRIPTION: Arcade drive, forward motion with left joystick, turn with 
     *              right joystick.
     *
     * RETURNS    : Void
     *************************************************************************/	
	void arcadeDrive();

    /**************************************************************************
     * FUNCTION   : arcadeDrive
     *
     * DESCRIPTION: Arcade drive, forward motion with <movement>, turn with 
     *              <rotate>.
     *
     * RETURNS    : Void
     *************************************************************************/	
	void arcadeDrive(double movement, double rotate);

    /**************************************************************************
     * FUNCTION   : twoBtnDrive
     *
     * DESCRIPTION: Create movement value out of two buttons.
     *
     * RETURNS    : Void
     *************************************************************************/	
	void twoBtnDrive();

private:
	float movementValue = 0.0;
	float rotationValue = 0.0;

	frc::DifferentialDrive *m_robotDrive;
	frc::Joystick *driveController1;
	frc::Joystick *driveController2;
    
    /**************************************************************************
     * FUNCTION   : twoBtnRotate
     *
     * DESCRIPTION: Create rotation value out of two buttons and joystick.
     *
     * RETURNS    : Void
     *************************************************************************/	
	void twoBtnRotate();
    
    /**************************************************************************
     * FUNCTION   : setMovement
     *
     * DESCRIPTION: Update <movementValue> to be used for drive.
     *
     * RETURNS    : Void
     *************************************************************************/	
	void setMovement();
    
    /**************************************************************************
     * FUNCTION   : setRotate
     *
     * DESCRIPTION: Update <rotateValue> to be used with drive.
     *
     * RETURNS    : Void
     *************************************************************************/	
	void setRotate(bool rotateEn = true);
};

#endif /* DRIVER_HELPER_HPP */
