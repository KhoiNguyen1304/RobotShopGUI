#ifndef __LOCOMOTOR_H
#define __LOCOMOTOR_H 2016

#include "RobotPart.h"

class Locomotor: public RobotPart {
	public:
		Locomotor(std::string name, int partNumber, double weight, double cost,
			      std::string description, int partType, double kPowerConsumeW, double kMaxSpeed);
		double GetMaxSpeed();
		double GetPowerConsumeW();

	private:
		double PowerConsumeW;
		double MaxSpeed;
};
#endif