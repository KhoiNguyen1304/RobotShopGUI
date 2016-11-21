#include "RobotPart.h"
#include "Arm.h"
#include <iostream>
#include <sstream>

using namespace std;

Arm::Arm(std::string name, int partNumber, double weight, double cost,
		std::string description, int partType, double kPowerConsumeW) : 
		RobotPart(name, partNumber, weight, cost, description, partType), PowerConsumeW(kPowerConsumeW) {};

double Arm::GetPowerConsumeW() {return PowerConsumeW;}

std::string Arm::print()
{
	ostringstream of;

	of << "Part name: " << GetName() 
	<< endl << "Part #: " << GetPartNumber() 
	<< endl << "Weight: " << GetWeight() 
	<< endl << "Cost: " << GetCost()
	<< endl << "Power consume: " << GetPowerConsumeW()
	<< endl << "Description: " << GetDescription() << endl;

	return of.str();
}