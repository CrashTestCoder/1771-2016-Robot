/*
 * Transmission.hpp
 *
 *  Created on: Jan 18, 2016
 *      Author: ryanmchale
 */

#ifndef SRC_TRANSMISSION_HPP_
#define SRC_TRANSMISSION_HPP_

Solenoid* shift = new Solenoid(0);

template<class motorController>
struct Transmission : motorController
{
public:
	explicit Transmission(int t1,int t2):
		con1{new motorController(t1)},
		con2{new motorController(t2)}
	{
		con1->SetFeedbackDevice(CANTalon::QuadEncoder);
		con1->SetControlMode(CANSpeedController::kCurrent);
		con1->ConfigNeutralMode(CANSpeedController::kNeutralMode_Coast);
		con1->EnableControl();

		con2->SetFeedbackDevice(CANTalon::QuadEncoder);
		con2->SetControlMode(CANSpeedController::kCurrent);
		con2->ConfigNeutralMode(CANSpeedController::kNeutralMode_Coast);
		con2->EnableControl();
	}
	void Shove(double j1)
	{
	}
private:
	motorController *con1,
					*con2;
};

#endif /* SRC_TRANSMISSION_HPP_ */
