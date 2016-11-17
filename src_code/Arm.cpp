#include "RobotPart.h"
#include "Arm.h"

Arm::Arm(std::string name, int partNumber, double weight, double cost,
		std::string description, int partType, double kPowerConsumeW) : 
		RobotPart(name, partNumber, weight, cost, description, partType), PowerConsumeW(kPowerConsumeW) {};

double Arm::GetPowerConsumeW() {return PowerConsumeW;}