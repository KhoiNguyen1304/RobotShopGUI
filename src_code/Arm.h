#ifndef __ARM_H
#define __ARM_H 2016

#include "RobotPart.h"

class Arm: public RobotPart {
	public:
		Arm(std::string name, int partNumber, double weight, double cost,
			 std::string description,int partType, double kPowerConsumeW);
		double GetPowerConsumeW();
	private:
		double PowerConsumeW;
};
#endif