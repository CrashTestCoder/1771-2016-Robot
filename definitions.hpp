#ifndef DEFINITIONS_H_P_P
#define DEFINITIONS_H_P_P

// Arm
#define ARM_POS_MIN 0.0
#define ARM_POS_MAX 1.0

#include<stdarg.h>
bool GetRawButtons(Joystick& j, int quantity,...)
{
	va_list vl;
	va_start(vl,quantity);
	for(int i=0;i<quantity;i++)
		if(j.GetRawButton(va_arg(vl,int)))
			return true;
	return false;
}

#endif // DEFINITIONS_H_P_P
