#include "RobotPart.h"
#include "Locomotor.h"

Locomotor::Locomotor(std::string name, int partNumber, double weight, double cost,
			std::string description, int partType, double kPowerConsumeW, double kMaxSpeed) :
			RobotPart(name, partNumber, weight, cost, description, partType), PowerConsumeW(kPowerConsumeW), MaxSpeed(kMaxSpeed) {};

double Locomotor::GetMaxSpeed() {return MaxSpeed;};

double Locomotor::GetPowerConsumeW() {return PowerConsumeW;};			 