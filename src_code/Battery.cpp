#include "RobotPart.h"
#include "Battery.h"

Battery::Battery(std::string name, int partNumber, double weight, double cost,
			 std::string description, int partType, double kilowattHours) :
			 RobotPart(name, partNumber, weight, cost, description, partType), KilowattHours(kilowattHours) {};

double Battery::GetKilowattHours() {return KilowattHours;};