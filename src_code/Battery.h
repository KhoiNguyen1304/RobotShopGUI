#ifndef __BATTERY_H
#define __BATTERY_H 2016

#include "RobotPart.h"

class Battery: public RobotPart {
	public:
		Battery(std::string name, int partNumber, double weight, double cost,
			 std::string description, int partType, double kilowattHours);
		double GetKilowattHours();
		
	private:
		double KilowattHours;
};
#endif