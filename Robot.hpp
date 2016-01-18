#ifndef SRC_ROBOT_HPP_
#define SRC_ROBOT_HPP_

#include "Lib1771.hpp"
#include "robotMap.h"
#include "definitions.hpp"
class Robot: public SampleRobot
{
public:
	Robot():
		lstick(LEFT_JOYSTICK),
		rstick(RIGHT_JOYSTICK),
		ltalon(0,1),
		rtalon(2,3),
		arm(ARM_TALON)
	{

	}

	void Autonomous(void);

	void OperatorControl(void);

	void Test(void);

	void Disabled(void);

private:
	Joystick lstick,
			 rstick;

	Transmission<CANTalon> ltalon,
						   rtalon;

	Arm arm;
};

START_ROBOT_CLASS(Robot);

#endif /* SRC_ROBOT_HPP_ */
