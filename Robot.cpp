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
