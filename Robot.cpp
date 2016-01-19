#include "Robot.hpp"

void Robot::Autonomous(void)
{
	// Prepare for Autonomous
	while (IsAutonomous() && IsEnabled())
	{
		Wait(0.005);
	}
}

void Robot::OperatorControl(void)
{
	// Prepare for Match
	while (IsOperatorControl() && IsEnabled())
	{
	// Drive
		double driveL=lstick.GetY(),
				driveR=rstick.GetY();
		if(lstick.GetRawButton(10) || rstick.GetRawButton(12))
		{
			ltalon.Shove(driveL);
			rtalon.Shove(driveR);
		}
		else
		{
			ltalon.Set(driveL);
			rtalon.Set(driveR);
		}


		Wait(0.005);				// wait for a motor update time
	}
}

void Robot::Test(void)
{
	while (IsTest() && IsEnabled())
	{
		Wait(0.005);
	}
}

void Robot::Disabled(void)
{
	rtalon.Set(1);
}
