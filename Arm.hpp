#ifndef ARM_H_P_P
#define ARM_H_P_P

#include "WPILib.h"
#include "definitions.hpp"

class Arm
{
public:
	explicit Arm(int channel):
		arm(channel)
	{
		arm.SetControlMode(CANSpeedController::kPosition);
		arm.SetFeedbackDevice(CANTalon::AnalogPot);
		arm.ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
		arm.ConfigLimitMode(CANSpeedController::kLimitMode_SoftPositionLimits);
		arm.ConfigSoftPositionLimits(ARM_POS_MIN,
									 ARM_POS_MAX);
		arm.EnableControl();
	}
	~Arm();

	void Set(float pos);  // Uses CANTalon::SetSetPoint(float)

private:
	CANTalon arm;
};

#endif // ARM_H_P_P
