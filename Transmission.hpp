/*
 * Transmission.hpp
 *
 *  Created on: Jan 18, 2016
 *      Author: ryanmchale
 */

#ifndef SRC_TRANSMISSION_HPP_
#define SRC_TRANSMISSION_HPP_

#include"robotMap.h"

Solenoid* shift = new Solenoid(SHIFT_SOLENOID);

struct Transmission : CANTalon
{
public:
	explicit Transmission(int t1,int t2)
	{
		con1 = new CANTalon(t1);
		con1->SetFeedbackDevice(CANTalon::QuadEncoder);
		con1->SetControlMode(CANSpeedController::kCurrent);
		con1->ConfigNeutralMode(CANSpeedController::kNeutralMode_Coast);
		con1->EnableControl();

		con2 = new CANTalon(t2);
		con2->SetFeedbackDevice(CANTalon::QuadEncoder);
		con2->SetControlMode(CANSpeedController::kCurrent);
		con2->ConfigNeutralMode(CANSpeedController::kNeutralMode_Coast);
		con2->EnableControl();
	}
	virtual ~Transmission();

	/**
	 * General percentage based speed control
	 * params: -1 - 1
	 */
	void Set(float set)
	{
		if(con1->GetControlMode()!=CANSpeedController::kPercentVbus)
			con1->SetControlMode(CANSpeedController::kPercentVbus);
		con1->Set(set);
		con2->Set(set);
	}

	/**
	 * Prevents the breaker from blowing and
	 * increases torque in a shoving match
	 */
	void Shove(double set)
	{
		shift->Set(0);			// Shift to low gear
		set-=set/80;			// Prevent breaker from blowing
		set*=40;
		if(con1->GetControlMode()!=CANSpeedController::kCurrent)
			con1->SetControlMode(CANSpeedController::kCurrent);
		con1->Set(set);
		con2->Set(set);
	}
private:
	CANTalon *con1,
		 *con2;
};

#endif /* SRC_TRANSMISSION_HPP_ */
