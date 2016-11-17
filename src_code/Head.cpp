#include "Head.h"
#include "RobotPart.h"


Head::Head(std::string name, int partNumber, double weight, double cost,
		   std::string description, int partType) :
	RobotPart(name, partNumber, weight, cost, description, partType) {};
